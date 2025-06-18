#ifndef MONSTER_H
#define MONSTER_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "enemy.h"
using namespace sf;
using namespace std;
class Monster : public Enemy
{
public:
    Monster()
    {
        tex.loadFromFile("img/monster.png");
        sprite.setTexture(tex);
        sprite.setPosition(220, 0);
        sprite.setScale(0.2, 0.2);
    }

    void bomb_fire(int x, int y)
    {
        if (x == 1)
        {

            sprite.move(0.3, 0);
            sprite1.move(0.3, 0);
        }
        else if (x == 2)
        {
            sprite.move(-0.3, 0);
            sprite1.move(-0.3, 0);
        }
    }
    void bomb_move()
    {

        tex1.loadFromFile("img/PNG/Lasers/laserBlue12.png");
        sprite1.setTexture(tex1);
        sprite1.setPosition(340, 110);
        sprite1.setScale(2, 10);
    }
    void tiltedDragon(int x){}
    void setDragon(){}
};
#endif