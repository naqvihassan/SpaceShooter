#ifndef BETA_H
#define BETA_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "invader.h"
// #include "enemy.h"
using namespace sf;
using namespace std;
class Beta : public Invader
{
public:
    Beta()
    {
    }
    Beta(int x, int y, string pic = "img/PNG/Enemies/enemyBlue2.png") : Invader(x, y, pic)
    {
    }
    void bomb_fire(int x, int y)
    {
        // b->sprite.setPosition(x+50,y+50);
        b = new Bomb(sprite.getPosition().x , sprite.getPosition().y);
    }
    void bomb_move()
    {
        //b->inter = 3;
        b->sprite.move(0,0.40);
    }
    void tiltedDragon(int x){}
    void setDragon(){}
};

#endif