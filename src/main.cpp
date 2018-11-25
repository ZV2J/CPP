#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "bibli.hpp"
#include "structs.hpp"

/*
    g++ -std=c++14 src/*.cpp -o bin/prog -I include -L lib -lsfml-graphics -lsfml-window -lsfml-system
*/

int main()
{
    sf::RenderWindow window;

    sf::Font font;

    if(!font.loadFromFile("src/police/arial.ttf"))
        SF_Error(&window);

    window.create(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }

        window.clear(sf::Color::Black);

        window.display();
    }

    return 0;
}