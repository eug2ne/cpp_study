#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <chrono>

using namespace std;

double get_delta_time()
{
    static auto lastTime = std::chrono::steady_clock::now(); // executed only once
    auto currentTime = std::chrono::steady_clock::now();

    double delta = std::chrono::duration<double>(currentTime - lastTime).count();
    lastTime = currentTime;

    return delta;
}

int _process(float delta)
{
    // game process function
    cout << delta;
}

int main()
{
    // create window
    sf::RenderWindow window(sf::VideoMode(960, 540), "Snake Game", sf::Style::Close);

    // create snake 
    sf::RectangleShape shape(sf::Vector2f(30.f,30.f));
    shape.setFillColor(sf::Color::Green);

    // initialize timestamp
    get_delta_time();

    // create game loop
    while (window.isOpen())
    {
        // activate _process
        float dt = get_delta_time();
        _process(dt);

        // handle input event
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            { 
                case sf::Event::Closed:
                    // close window when window-close button click
                    window.close();
                    break;
                
                case sf::Event::KeyPressed:
                        if (event.key.code == sf::Keyboard::Escape)
                        {
                            // close window when esc key pressed
                            window.close();
                        }

                        // snake movement
                        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
                        {
                            // up key pressed
                            shape.move(0.f, -5.f);
                        }
                        if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::A)
                        {
                            // right key pressed
                            shape.move(5.f, 0.f);
                        }
                        if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
                        {
                            // down key pressed
                            shape.move(0.f, 5.f);
                        }
                        if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::D)
                        {
                            // left key pressed
                            shape.move(-5.f, 0.f);
                        }
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}