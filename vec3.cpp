#include "Vec3.h"
#include <cmath>
#include <iostream>
using std::cout;

double Vec3::module() {
	return sqrt(x * x + y * y + z * z);
}

double Vec3::module2() {
	return (x * x + y * y + z * z);
}

void Vec3::normalize() {
	double mod = module();
	if (mod == 0) return;
	x /= mod;
	y /= mod;
	z /= mod;
}

Vec3 Vec3::operator +(Vec3 a) {
	return { x + a.x, y + a.y, z + a.z };
}

Vec3 Vec3::operator -(Vec3 a) {
	return { x - a.x, y - a.y, z - a.z };
}

Vec3 Vec3::operator *(double n) {
	return { x * n, y * n, z * n };
}
Vec3 Vec3::operator /(double n) {
	return { x / n, y / n, z / n };
}

bool Vec3::operator ==(Vec3 a) {
	return (a.x == x && a.y == y && a.z == z);
}

bool Vec3::operator !=(Vec3 a) {
	return !(a.x == x && a.y == y && a.z == z);
}

void Vec3::print() {
	cout << '(' << x << ", " << y << ", " << z << ")\n";
}

Vec3 Vec3::norm() {
	double l = module();
	return {x / l, y / l, z / l};
}