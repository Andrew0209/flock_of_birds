#pragma once
#include "Bird.h"
#include <vector>
#include "structures.h"
#include <iostream>

using std::vector;

struct Node
{
	Bird* self;
	Node* next;
	Node(Bird* bird) : self(bird), next(nullptr) {}
};

struct List
{
	Node* first;
	Node* last;
	List() : first(nullptr), last(nullptr) {}

	void add(Bird* bird) {
		Node* p = new Node(bird);
		if (last == nullptr) last = p;
		p->next = first;
		first = p;
		size++;
		//if (size > 100)std::cout << "shit!\n";
	}
	void add(List a) {
		if (last == nullptr) {
			first = a.first;
			last = a.last;
		}
		else
		last->next = a.first;
	}

	void remove(Bird* a) {
		if (first == nullptr)return;
		if (first->self == a) {
			first = first->next;
			size--;
			return;
		}
		Node* _first = first;
		while (_first->next != nullptr) {
			if (a == _first->next->self) {
				_first->next = _first->next->next;
				size--;
				return;
			}
			_first = _first->next;
		}
	}
	int get_size() { return size; }
private:
	int size = 0;
};


class Grid
{
private:
	vector<vector<vector<List>>> field;
	Border borders;
	Vec3 start_point;
	int cell_size;
	int size_x, size_y, size_z;
public:
	Grid(Border border, int _cell_size) {
		borders = border;
		cell_size = _cell_size;
		start_point = border.bottom_corner;
		size_x = (border.top_corner.x - border.bottom_corner.x) / _cell_size + 1;
		size_y = (border.top_corner.y - border.bottom_corner.y) / _cell_size + 1;
		size_z = (border.top_corner.z - border.bottom_corner.z) / _cell_size + 1;
		field = vector<vector<vector<List>>>(size_x, vector<vector<List>>(size_y, vector<List>(size_z)));
	}

	void update(Bird* bird) {
		Cell pos = bird->get_cell();
		Vec3 new_pos = bird->pos;
		constrain(new_pos, borders.bottom_corner, borders.top_corner);
		Cell new_cell = (new_pos - start_point) / cell_size;	
		if (new_cell == pos)return;
		constrain(pos.x, 0, size_x - 1);
		constrain(pos.y, 0, size_y - 1);
		constrain(pos.y, 0, size_z - 1);
		field[pos.x][pos.y][pos.z].remove(bird);
		field[new_cell.x][new_cell.y][new_cell.z].add(bird);
		bird->update_cell(new_cell);
	}

	List nearby_birds(Bird* bird) {
		bird->get_cell();
		int posx = bird->get_cell().x, posy = bird->get_cell().y, posz = bird->get_cell().z;
		List ans = field[posx][posy][posz];

		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				for (int k = -1; k < 2; k++) {
					if ((posx + i >= 0) && (posy + j >= 0) && (posz + k >= 0) && 
						(posx + i < size_x) && (posy + j < size_y) && (posz + k < size_z) && 
						!(i == 0 && j == 0 && k == 0))
						ans.add(field[posx + i][posy + j][posz + k]);
				}
			}
		}
		return ans;
		
	}
};

