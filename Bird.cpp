#include "Bird.h"
#include <iostream>
using std::cout;

void Bird::update() {
	pos = pos + vel * dt;
	vel = vel + acc * dt;
}
void Bird::print() {
	cout << "pos: ";
	pos.print();
	cout << "vel: ";
	vel.print();
	cout << "acc: ";
	acc.print();
}