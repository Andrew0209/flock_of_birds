#include "Flock.h"
//#include <iostream>

Flock::Flock(int n) {
	Bird bird;
	bird.set_dt(&dt);
	int k = sqrt(n);
	birds.resize(n);
	while (n--) {
		bird.pos = { (n % k) * danger_radius, (n / k) * danger_radius, 0.0};
		birds[n] = bird;
	}

}

void Flock::add(Bird& a) {
	birds.push_back(a);
	birds[birds.size()].set_dt(&dt);
}

void Flock::update() {

	for (int i = 0; i < size(); i++) {

		double k = 0.9;
		birds[i].acc = birds[i].acc * k + ((birds[i].pos - target) * -k1 - birds[i].vel * k2) * (1.-k);
		// update acceleration

		int count = 0;
		Vec3 aligment_vel;
		for (int j = 0; j < size(); j++) {
			if (i == j)continue;
			Vec3 dist = birds[j].pos - birds[i].pos;
			// boids
			if (dist.module() <= danger_radius) {
				Vec3 pushing = dist.norm() * (danger_radius * danger_radius / dist.module2() - 1);
				birds[i].acc = birds[i].acc * 0.9 - pushing * 0.1;
				//pushing.print();
			}
			if (dist.module() <= alignment_radius) {
				count++;
				aligment_vel = aligment_vel + birds[j].vel;
			}	
		}
		if (count != 0) {
			aligment_vel = aligment_vel / count;
			birds[i].vel = birds[i].vel * 0.8 + aligment_vel * 0.2;
		}
		shuffle(birds[i].vel, 0.05);

		double vel = birds[i].vel.module();
		if (vel > max_speed) {
			//birds[i].vel = birds[i].vel.norm() * max_speed;
			birds[i].acc = birds[i].acc - birds[i].vel.norm() * (vel - max_speed);
			//std::cout << "limit max_speed\n";
		}
		if (vel < min_speed) {
			//birds[i].vel = birds[i].vel.norm() * min_speed;
			birds[i].acc = birds[i].acc + birds[i].vel.norm() * (min_speed - vel);
			//std::cout << "limit min speed\n";
		}

		birds[i].update();
		//birds[i].print();
	}

}

