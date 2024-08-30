#include "Flock.h"
//#include <iostream>

Flock::Flock(int n) {
	Bird bird;
	bird.set_dt(&dt);
	int k = cbrt(n);
	birds.resize(n);
	Vec3 start(100, 100, 100);
	while (n--) {
		bird.pos = Vec3{ (n % k) * danger_radius, ((n / k) % k) * danger_radius, (n / (k*k)) * danger_radius } + start;
		birds[n] = bird;
		birds[n].update_cell(bird.pos / cell_size);
		//field->update(&birds[n]);
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

		// find birds within some radius
		// use grid 
		if (field != nullptr) {
			List a = field->nearby_birds(&birds[i]);
			for (; a.first != nullptr; a.first = a.first->next) {
				Vec3 dist = a.first->self->pos - birds[i].pos;

				if (dist.module() <= danger_radius) {
					Vec3 pushing = dist.norm() * (danger_radius * danger_radius / (dist.module2() + 0.0001) - 1);
					birds[i].acc = birds[i].acc * 0.8 - pushing * 0.2;
					//pushing.print();
				}
				if (dist.module() <= alignment_radius) {
					count++;
					aligment_vel = aligment_vel + a.first->self->vel;
				}
			}
		}

		else {
			for (int j = 0; j < size(); j++) {
				if (i == j)continue;
				Vec3 dist = birds[j].pos - birds[i].pos;
				// boids
				if (dist.module() <= danger_radius) {
					Vec3 pushing = dist.norm() * (danger_radius * danger_radius / (dist.module2() + 0.0001) - 1);
					birds[i].acc = birds[i].acc * 0.9 - pushing * 0.1;
					//pushing.print();
				}
				if (dist.module() <= alignment_radius) {
					count++;
					aligment_vel = aligment_vel + birds[j].vel;
				}
			}
		}

		if (count != 0) {
			aligment_vel = aligment_vel / count;
			birds[i].vel = birds[i].vel * 0.8 + aligment_vel * 0.2;
		}

		// update velosity
		shuffle(birds[i].vel, 0.03);
		double vel = birds[i].vel.module();
		if (vel > max_speed) {
			birds[i].acc = birds[i].acc - birds[i].vel.norm() * (vel - max_speed);
		}
		if (vel < min_speed) {
			birds[i].acc = birds[i].acc + birds[i].vel.norm() * (min_speed - vel);
		}

		birds[i].update();
		if (field == nullptr)continue;
		field->update(&birds[i]);
		//birds[i].print();
	}

}

