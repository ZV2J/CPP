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
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window;

    int sprite_w = 32;
    int sprite_h = 32;

    window.create(sf::VideoMode(WIN_W, WIN_H), "My window");
    window.setFramerateLimit(144);

    if(!texture.loadFromFile("src/image.png"))
        SF_Error(&window);

    texture.setSmooth(true);

    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f((WIN_W - sprite_w) / 2, (WIN_H - sprite_h) / 2));

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            {
                sprite.move(0, -10);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0.f, 10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-10.f, 0.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    sprite.move(10.f, 0.f);       
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                sprite.move(0.f, 10.f);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0.f, -10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-10.f, 0.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                sprite.move(10.f, 0.f);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                sprite.move(-10.f, 0.f);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0.f, -10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0.f, 10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    sprite.move(10.f, 0.f);

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                sprite.move(10.f, 0.f);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0.f, -10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0.f, 10.f);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-10.f, 0.f);
            }

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

                default:
                    break;
            }
                    
        }

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display(); 
    }

    return 0;
}