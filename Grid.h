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
	Grid(Border border, int _cell_size);
	void update(Bird* bird);
	List nearby_birds(Bird* bird);
};

