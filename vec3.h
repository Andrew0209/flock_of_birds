#pragma once
#include <cmath>

class Vec3
{
public:
	template <typename T>
	Vec3(T _x, T _y, T _z):x(_x), y(_y), z(_z) {}
	double x, y, z;
	double module();
	void normalize();
	Vec3 operator +(Vec3 a);
	Vec3 operator -(Vec3 a);
	Vec3 operator *(double n);
	bool operator ==(Vec3 a);
	bool operator !=(Vec3 a);
	void print();
};

