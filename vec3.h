#pragma once
#include <cmath>

class Vec3
{
public:
	template <typename T>
	Vec3(T _x, T _y, T _z) :x(_x), y(_y), z(_z) {}
	Vec3() :x(0), y(0), z(0) {}
	double x, y, z;
	double module();
	double module2();
	void normalize();
	Vec3 norm();
	void print();
	Vec3 operator +(Vec3 a);
	Vec3 operator -(Vec3 a);
	Vec3 operator *(double n);
	Vec3 operator /(double n);
	bool operator ==(Vec3 a);
	bool operator !=(Vec3 a);
};

Vec3 rand_vec3();
void shuffle(Vec3& vec, const double& k = 0.1);
double rand(const double& min, const double& max);
void constrain(double& val, const double& min, const double& max);

