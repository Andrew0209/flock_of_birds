#include "Vec3.h"
#include <cmath>
#include <iostream>
#include <random>

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
	if (l == 0)return { 0, 0, 0 };
	return {x / l, y / l, z / l};
}

Vec3 rand_vec3() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(-1.0, 1.0);
	Vec3 ans(dis(gen), dis(gen), dis(gen));
	ans.normalize();
	return ans;
}

void shuffle(Vec3& vec, const double& k) {
	vec = vec + rand_vec3() * k * vec.module();
}

double rand(const double& min, const double& max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(min, max);
	return dis(gen);
}
void constrain(double& val, const double& min, const double& max) {
	if (val < min)val = min;
	if (val > max) val = max;
}