#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cstdlib>
#include "bibli.hpp"
#include "structs.hpp"

void SF_Error(sf::RenderWindow *p1, const char *p2)
{
    std::cout << "error : " << p2 << std::endl;
    (*p1).close();
    exit(EXIT_FAILURE);
}