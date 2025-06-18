#ifndef ALPHA_H
#define ALPHA_H
// #include"invader.h"

#include <SFML/Graphics.hpp>
#include <string.h>
#include "invader.h"
using namespace sf;
using namespace std;
class Alpha : public Invader
{
public:
    Alpha()
    {
    }
    Alpha(int x, int y, string pic = "img/PNG/Enemies/enemyBlue1.png") : Invader(x, y, pic)
    {
    }
    void bomb_fire(int x, int y)
    {
        // b->sprite.setPosition(x+50,y+50);
        b = new Bomb(sprite.getPosition().x, sprite.getPosition().y);
        //bomb_move();
    }
    void bomb_move()
    {
        //b->inter = 5;
        b->sprite.move(0 ,0.40 );
        
    }
    void tiltedDragon(int x){}
    void setDragon(){}

};

#endif