#include "Bird_texture.h"
#include <iostream>

void Bird_texture::draw(RenderWindow& window) {
    bird_shape.setPosition(bird_data->pos.x, bird_data->pos.y);
    bird_shape.setFillColor(bird_color);
    double new_bird_size = 0.0;
    if (bird_data->pos.z >= -400)
        new_bird_size = bird_size / (1 + bird_data->pos.z / 500);

    bird_shape.setRadius(new_bird_size);
    window.draw(bird_shape);

    if (draw_direction) {
        Vec3 dir = bird_data->vel.norm();
        dir.z = 0;
        double angle = atan2(dir.y, dir.x);
        direction = RectangleShape(Vector2f(2 * bird_size * dir.module(), 5));
        direction.setFillColor(Color(150, 0, 0, 100));
        direction.setPosition(bird_data->pos.x + new_bird_size / 2, bird_data->pos.y + new_bird_size / 2);
        window.draw(direction);
    }
}
Bird_texture::Bird_texture(Bird* bird) {
    bird_data = bird;
    bird_shape.setFillColor(bird_color);
    bird_shape = CircleShape(bird_size);
}