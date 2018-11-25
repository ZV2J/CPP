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

    sf::Text text;

    text.setFont(font);
    text.setString("hello world");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);

    text.setPosition((WIN_W - text.getPosition().x) / 2, (WIN_H - text.getPosition().x) / 2);

    window.create(sf::VideoMode(WIN_W, WIN_H), "My window", sf::Style::Fullscreen);

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
        window.draw(text);
        window.display(); 
    }

    return 0;
}