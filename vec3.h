#pragma once
#include <cmath>

class vec3
{
public:
	vec3(double _x, double _y, double _z):x(_x), y(_y), z(_z) {}
	double x, y, z;
	double module();
	void normalize();
	vec3 operator +(vec3 a);
	vec3 operator -(vec3 a);
	vec3 operator *(double n);
	bool operator ==(vec3 a);
	bool operator !=(vec3 a);
};

