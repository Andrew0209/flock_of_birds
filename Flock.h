#pragma once
#include "Bird.h"
#include <vector>
#include <random>

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
	double danger_radius = 100;
	double k1 = 0.005;
	double k2 = 0.02;
	double min_speed = 10.0;
	double max_speed = 40.0;
};

