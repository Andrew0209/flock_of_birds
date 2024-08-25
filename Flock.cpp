#include "Flock.h"

Flock::Flock(int n) {
	Bird bird;
	bird.set_dt(dt);
	int k = sqrt(n);
	birds.resize(n);
	while (n--) {
		bird.pos = { (n % k) * danger_radius, (n / k) * danger_radius, 0.0};
		birds[n] = bird;
	}

}

void Flock::add(Bird& a) {
	birds.push_back(a);
	birds[birds.size()].set_dt(dt);
}

void Flock::update() {
	for (int i = 0; i < size(); i++) {
		birds[i].acc = (birds[i].pos - target) * -k1 - birds[i].vel * k2;
		// update acceleration
		for (int j = 0; j < size(); j++) {
			if (i == j)continue;
			Vec3 dist = birds[j].pos - birds[i].pos;
			if (dist.module() <= danger_radius) {
				Vec3 pushing = dist.norm() * (danger_radius * danger_radius / dist.module2() - 1);
				birds[i].acc = birds[i].acc - pushing;
				//pushing.print();
			}
			
		}
		birds[i].update();
		//birds[i].print();
	}

}

