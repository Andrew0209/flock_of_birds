#pragma once

struct Border
{
	Vec3 top_corner, bottom_corner;
	Border() : top_corner({ 100, 100, 100 }), bottom_corner({ 0,0,0 }) {}
	Border(Vec3 top, Vec3 bottom) : top_corner(top), bottom_corner(bottom) {}
};

struct Cell
{
	int x, y, z;
	Cell(int _x, int _y, int _z) : x(_x), y(_y), z(_z) {}
	Cell(Vec3 a) : x(a.x), y(a.y), z(a.z) {};
	Cell() : x(0), y(0), z(0) {}

	Cell operator+(Cell a) { return Cell(x + a.x, y + a.y, z + a.z); }
	Cell operator-(Cell a) { return Cell(x - a.x, y - a.y, z - a.z); }
	bool operator==(Cell a) { return x == a.x && y == a.y && z == a.z; }
};
