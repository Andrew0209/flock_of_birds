#pragma once
#include "Bird.h"
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

private:
	double dt = 0.1;
	double danger_radius = 50;
	double k1 = 0.005;
	double k2 = 0.05;
};

