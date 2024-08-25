#include <SFML/Graphics.hpp>
#include "Vec3.h"
#include "Bird.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "test bird", sf::Style::Default, settings);
    sf::CircleShape bird(10.f);
    bird.setFillColor(sf::Color::Green);
    Bird bird1;
    bird1.pos = { 300, 300, 0 };
    Vec3 target = { 0,0,0 };
    double k1 = 0.005;
    double k2 = 0.05;
    bird1.set_dt(0.1);

    while (window.isOpen())
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        target = { mouse_pos.x, mouse_pos.y, 0};

        bird1.acc = (bird1.pos - target) * -k1 - bird1.vel * k2;
        bird1.update();
        bird.setPosition( bird1.pos.x, bird1.pos.y);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(bird);
        window.display();
    }

    return 0;
}