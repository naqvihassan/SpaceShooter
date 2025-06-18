#ifndef Life_H
#define Life_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "addon.h"
using namespace sf;
using namespace std;
class Life : public AddOn
{
public:
    Life()
    {
        tex.loadFromFile("img/PNG/Power-ups/powerupBlue_star.png");
        sprite.setTexture(tex);
        sprite.setPosition(10, 10);
        sprite.setScale(1, 1);
    }
    
};
#endif