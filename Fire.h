#ifndef FIRE_H
#define FIRE_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "addon.h"
using namespace sf;
using namespace std;
class Fire : public AddOn
{
public:
    Fire()
    {
        tex.loadFromFile("img/PNG/Power-ups/pill_red.png");
        sprite.setTexture(tex);
        sprite.setPosition(10, 10);
        sprite.setScale(1, 1);
    }
    
};
#endif