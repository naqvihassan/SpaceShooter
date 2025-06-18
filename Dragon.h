#ifndef DRAGON_H
#define DRAGON_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "enemy.h"
using namespace sf;
using namespace std;
class Dragon : public Enemy
{
public:
    Dragon()
    {
        tex.loadFromFile("img/dragon.png");
        sprite.setTexture(tex);
        sprite.setPosition(220, 0);
        sprite.setScale(1.3, 1.3);
    }

    void bomb_fire(int x, int y)
    {
        tex1.loadFromFile("img/PNG/Lasers/dragonFire (1).png");
        sprite1.setTexture(tex1);
        sprite1.setPosition(360, 280);
        sprite1.setScale(1, 6);
    }
    void bomb_move() {
        
    }
    void tiltedDragon(int x)
	{
		if (x == 1)
		{
			tex1.loadFromFile("img/PNG/Lasers/dragonFireRight (1).png");
			sprite1.setTexture(tex1);
			sprite1.setPosition(330, 280);
			sprite1.setScale(8.0f, 3.0f);
		}
		else if (x == 2)
		{
			tex1.loadFromFile("img/PNG/Lasers/dragonFireLeft (2).png");

			sprite1.setTexture(tex1);
			sprite1.setPosition(70, 270);
			sprite1.setScale(6.0f, 3.0f);
		}
	}
    void setDragon()
    {
        tex1.loadFromFile("img/PNG/Lasers/dragonFire (1).png");
        sprite1.setTexture(tex1);
        sprite1.setPosition(350, 280);
        sprite1.setScale(1, 6);
    }

};
#endif