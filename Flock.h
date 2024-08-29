#pragma once
#include "Bird.h"
#include "Grid.h"
#include <vector>

using std::vector;

class Flock
{
public:
	vector<Bird> birds;
	Vec3 target{ 0, 0, 0 };

	Flock(int n);
	void add(Bird& a);
	uint32_t size() { return birds.size(); }
	void update();

	void set_dt(double new_dt) { dt = new_dt; }
	double get_dt() { return dt; }
	Border get_border() { return border; }
	void set_border(Border _border) { border = _border; }
	void set_grid(Grid* _field) { field = _field; }
	int get_cell_size() { return cell_size; }
	Border getBorder() { return border; }
private:
	const int cell_size = 100;
	double dt = 1.;
	double danger_radius = 50;
	double alignment_radius = 100;
	double border_aware_radius = 100;
	double k1 = 0.01;
	double k2 = 0.05;
	double min_speed = 15.0;
	double max_speed = 20.0;
	Border border;
	Grid* field = nullptr;
};

