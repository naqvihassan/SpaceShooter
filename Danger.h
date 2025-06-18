#ifndef DANGER_H
#define DANGER_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "addon.h"
using namespace sf;
using namespace std;
class Danger : public AddOn
{
public:
    Danger()
    {
        tex.loadFromFile("img/PNG/Lasers/laserRed09.png");
        sprite.setTexture(tex);
        sprite.setPosition(10, 10);
        sprite.setScale(1, 1);
    }
    
};
#endif