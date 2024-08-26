#pragma once
#include <SFML/Graphics.hpp>
#include "Bird.h"
using namespace sf;

class Bird_texture
{
public:
	Bird_texture(Bird* bird);
	Bird_texture();
	void draw(RenderWindow& window);
	void set_bird(Bird* bird) { bird_data = bird; }
	bool set_draw_direction(bool state) { draw_direction = state; }
private:
	Bird* bird_data = nullptr;
	CircleShape bird_shape;
	bool draw_direction = true;
	double bird_size = 20;
	Color bird_color = Color(80, 100, 255, 170);
};

