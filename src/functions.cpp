#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>
#include <cstdlib>
#include "bibli.hpp"
#include "structs.hpp"

void SF_Error(sf::RenderWindow *p)
{
    (*p).close();
}