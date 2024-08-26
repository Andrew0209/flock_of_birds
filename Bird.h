#pragma once
#include "Vec3.h"
class Bird
{
public:
	Vec3 pos, vel, acc;
	Bird() : pos({ 0, 0, 0 }), vel({ 0, 0, 0 }), acc({ 0, 0, 0 }) {}
	void set_dt(double* t){ dt = t; }
	void update();
	void print();
private:
	double* dt = 0;
};

