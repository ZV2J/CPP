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
    const float speed = 10.f;

    sf::Texture texture;
    sf::Sprite sprite;
    sf::RenderWindow window;

    sf::Clock clock;

    int sprite_w = 32;
    int sprite_h = 32;

    window.create(sf::VideoMode(WIN_W, WIN_H), "My window");
    window.setFramerateLimit(144);

    if(!texture.loadFromFile("src/image.png"))
        SF_Error(&window, "load src/image");

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
                sprite.move(0, -speed);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0, speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-speed, 0);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    sprite.move(speed, 0);       
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                sprite.move(0, speed);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0, -speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-speed, 0);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                sprite.move(speed, 0);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            {
                sprite.move(-speed, 0);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0, -speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0, speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    sprite.move(speed, 0);

            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                sprite.move(speed, 0);
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    sprite.move(0, -speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    sprite.move(0, speed);
                else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    sprite.move(-speed, 0);
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

        sf::Time time = clock.getElapsedTime();
        clock.restart();

        window.clear(sf::Color::Black);
        window.draw(sprite);
        window.display(); 
    }

    return 0;
}