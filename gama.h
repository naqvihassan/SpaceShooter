#ifndef GAMMA_H
#define GAMMA_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "invader.h"
using namespace sf;
class Gama : public Invader
{
public:
    Gama()
    {
    }
    Gama(int x, int y, string pic = "img/PNG/Enemies/enemyBlue3.png") : Invader(x, y, pic)
    {
    }
    void bomb_fire(int x, int y)
    {
        // b->sprite.setPosition(x+50,y+50);
        b = new Bomb(sprite.getPosition().x, sprite.getPosition().y);
    }
    void bomb_move()
    {
        //b->inter = 2;
        b->sprite.move(0,0.40);
    }
    void tiltedDragon(int x){}
    void setDragon(){}
};

#endif