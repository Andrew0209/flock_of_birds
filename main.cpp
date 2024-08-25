#include <SFML/Graphics.hpp>
#include "Flock.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "test bird", sf::Style::Default, settings);
    
    const int n = 50;
    vector<sf::CircleShape> birds(n);
    for (int i = 0; i < n; i++) {
        birds[i] = sf::CircleShape(10.f);
        birds[i].setFillColor(sf::Color(80, 100, 255, 70));
    }
    Flock flock(n);
    while (window.isOpen())
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        flock.target = { mouse_pos.x, mouse_pos.y, 10};
        flock.update();
        for (int i = 0; i < n; i++) {
            birds[i].setPosition(flock.birds[i].pos.x, flock.birds[i].pos.y);
            birds[i].setRadius(10.f / (1 + flock.birds[i].pos.z / 200));
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < n; i++)
            window.draw(birds[i]);
        window.display();
    }

    return 0;
}