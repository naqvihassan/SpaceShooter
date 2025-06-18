#ifndef ENEMY_H
#define ENEMY_H
#include "Bomb.h"

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <string.h>
#include <iomanip>
using namespace std;
using namespace sf;
class Enemy
{
public:
	Bomb *b;
	Sprite sprite1;
	Texture tex1;
	virtual void bomb_fire(int x, int y) = 0;
	virtual void bomb_move() = 0;
	virtual void tiltedDragon(int x) = 0;
	virtual void setDragon() = 0;

	Texture tex;
	Sprite sprite;
	float speed = 0.5;
	int x, y;
	bool active = true;
	Enemy(){};
	Enemy(int x, int y, string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setPosition(x, y);
		sprite.setScale(0.60, 0.60);
	}

	~Enemy()
	{
		if (b != nullptr)
		{
			delete b;
		}
	}
};
#endif // PLAYER_H
