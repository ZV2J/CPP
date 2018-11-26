#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cstdlib>
#include "bibli.hpp"
#include "structs.hpp"

/*
    g++ -std=c++14 src/*.cpp -o bin/prog -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system
*/

int main()
{
    sf::RenderWindow window;

    window.create(sf::VideoMode(WIN_W, WIN_H), "My window", sf::Style::Fullscreen);
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    switch(event.key.code)
                    {
                        case sf::Keyboard::Space:
                            window.close();
                            break;
                    }
                    break;

                case sf::Event::MouseButtonPressed:
                    switch(event.mouseButton.button)
                    {
                        case sf::Mouse::Left:
                            std::cout << "Left" << std::endl;
                            break;
                    }
                    break;

                default:
                    break;
            }
                    
        }

        window.clear(sf::Color::Black);
        window.display(); 
    }

    return 0;
}