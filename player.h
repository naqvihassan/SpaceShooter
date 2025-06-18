#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
#include "Bullets.h"
#include "Fire.h"
#include "addon.h"
using namespace std;
using namespace sf;

class Player
{
public:
	Texture tex;
	Sprite sprite;
	float speed = 1.5;
	int score = 0;
	int highestScore;
	int x, y;
	int lives = 3;
	Player(string png_path = "img/PNG/playerShip3_blue.png")
	{

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		x = 340;
		y = 520;
		sprite.setPosition(x, y);
		sprite.setScale(0.75, 0.75);
	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1;
		// move the player left
		else if (s == "r")
			delta_x = 1;
		// move the player right
		if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		float bound_x = sprite.getPosition().x + delta_x;
		float bound_y = sprite.getPosition().y + delta_y;

		// Check if player is out of screen bounds
		if (bound_x < 0)
			bound_x = 655;
		else if (bound_x > 655)
			bound_x = 0;

		if (bound_y < 0)
			bound_y = 560;
		else if (bound_y > 560)
			bound_y = 560;

		sprite.setPosition(bound_x, bound_y);
	}
	void setTiltedPlayerImage(int x)
	{
		if (x == 1)
		{
			tex.loadFromFile("img/PNG/playerShip3_blue_R1.png");
			sprite.setScale(1.2, 1.2);
		}
		else if (x == 2)
		{
			tex.loadFromFile("img/PNG/playerShip3_blue_L.png");
			sprite.setScale(1.2, 1.2);
		}
		// sprite.setTexture(tex);
	}
	void setPlayerImage()
	{
		tex.loadFromFile("img/PNG/playerShip3_blue.png");
		sprite.setScale(0.75, 0.75);
	}
	/////////////////////--BULLET--/////////////////

	Bullet *B = new Bullet("img/PNG/Lasers/laserBlue08.png");
	void setBullet()
	{
		if (B->bullet_timer.getElapsedTime().asSeconds() > B->fire_rate)
		{
			B->fire(sprite.getPosition().x, sprite.getPosition().y); // fire a bullet at player position
			B->bullet_timer.restart();								 // restart the bullet timer
		}
	}
	AddOn *Add;
	Sprite spriteA;
	Texture texA;
	// virtual void setAddOn() = 0;
	// virtual void moveAddOn() = 0; 


	//AddOn *AO = new AddOn(5, 5, "img/PNG/Lasers/laserBlue08.png");
};

#endif