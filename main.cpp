#include "Bird_texture.h"
#include "Flock.h"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "test flock", sf::Style::Default, settings);

    const int n = 200;
    const double bird_size = 20.0;
    vector<Bird_texture> birds(n);
    Flock flock(n);
    for (int i = 0; i < n; i++) birds[i].set_bird(&flock.birds[i]);
    double mouse_zpos = 500;

    while (window.isOpen())
    {
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        flock.target = { 1. * mouse_pos.x, 1. * mouse_pos.y, mouse_zpos };
        mouse_zpos = rand(mouse_zpos - 10, mouse_zpos + 10);
        constrain(mouse_zpos, 200, 700);
        flock.update();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < n; i++)
            birds[i].draw(window);
        window.display();
    }

    return 0;
}