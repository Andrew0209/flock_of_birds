#include "Bird_texture.h"
#include <iostream>

void Bird_texture::draw(RenderWindow& window) {
    if (bird_data->pos.x > window.getSize().x + 2 * bird_size
        || bird_data->pos.x < -2 * bird_size
        || bird_data->pos.y > window.getSize().y + 2 * bird_size
        || bird_data->pos.y < -2 * bird_size)
        return;
    bird_shape.setPosition(bird_data->pos.x, bird_data->pos.y);
    //bird_shape.setFillColor(bird_color);
    double new_bird_size = 0.0;
    if (bird_data->pos.z >= -400)
        new_bird_size = bird_size / (1 + bird_data->pos.z / 500);

    bird_shape.setRadius(new_bird_size);
    window.draw(bird_shape);

    if (draw_direction) {
        Vec3 dir = bird_data->vel.norm();
        dir.z = 0;
        Vector2f center(bird_data->pos.x + new_bird_size, bird_data->pos.y + new_bird_size);
        sf::Vertex line[] =
        {
            sf::Vertex(center),
            sf::Vertex(center + Vector2f(dir.x * 2 * new_bird_size, dir.y * 2 * new_bird_size))
        };
        line[0].color = Color(255, 0, 0, 200);
        line[1].color = Color(255, 0, 0, 200);
        window.draw(line, 2, sf::Lines);
    }
}
Bird_texture::Bird_texture(Bird* bird) {
    bird_data = bird;
    bird_shape = CircleShape(bird_size);
    bird_shape.setFillColor(bird_color);
}
Bird_texture::Bird_texture() {
    bird_shape = CircleShape(bird_size);
    bird_shape.setFillColor(bird_color);
}