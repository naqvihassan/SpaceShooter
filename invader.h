#ifndef INVADER_H
#define INVADER_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "enemy.h"
using namespace sf;
using namespace std;
class Invader : public Enemy
{
public:

    Invader() {}
    Invader(int x, int y, string pic) : Enemy(x, y, pic)
    {

    }
    void bomb_fire(int x, int y) {}
    void bomb_move() {}
    void tiltedDragon(int x){}
    void setDragon(){}

};
#endif