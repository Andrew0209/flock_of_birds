#include "vec3.h"
#include <cmath>

vec3::vec3(double _x, double _y, double _z) :x(_x), y(_y), z(_z) {}
double x, y, z;

double vec3::module() {
	return sqrt(x * x + y * y + z * z);
}

void vec3::normalize() {
	double mod = module();
	x /= mod;
	y /= mod;
	z /= mod;
}

vec3 vec3::operator +(vec3 a) {
	return { x + a.x, y + a.y, z + a.z };
}

vec3 vec3::operator -(vec3 a) {
	return { x - a.x, y - a.y, z - a.z };
}

vec3 vec3::operator *(double n) {
	return { x * n, y * n, z * n };
}

bool vec3::operator ==(vec3 a) {
	return (a.x == x && a.y == y && a.z == z);
}

bool vec3::operator !=(vec3 a) {
	return !(a.x == x && a.y == y && a.z == z);
}