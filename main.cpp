#include "Bird_texture.h"
#include "Flock.h"
#include <ctime>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "test flock", sf::Style::Default, settings);

    const int n = 1000;
    const double bird_size = 20.0;
    vector<Bird_texture> birds(n);
    Flock flock(n);
    for (int i = 0; i < n; i++) birds[i].set_bird(&flock.birds[i]);
    double mouse_zpos = 800;
    uint32_t time_start = clock(), time_end = clock();
    while (window.isOpen())
    {
        time_start = clock();
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        flock.target = { 1. * mouse_pos.x, 1. * mouse_pos.y, mouse_zpos };
        mouse_zpos = rand(mouse_zpos - 10   , mouse_zpos + 10);
        constrain(mouse_zpos, 400, 1000);
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
        time_end = clock();
        while(time_end < time_start + 30)time_end = clock();
        //double dt = 1.0 * (time_end - time_start) / 40.0;
        //flock.set_dt(dt);
        //std::cout << dt << '\n';
    }

    return 0;
}