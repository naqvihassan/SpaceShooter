#ifndef Bomb_H
#define Bomb_H
#include <SFML/Graphics.hpp>
#include <string.h>

using namespace sf;
class Bomb {
public:
Texture tex;
Sprite sprite;
float speed = 1.5;
Bomb(int x, int y, string png_path = "img/PNG/Lasers/laserBlue16.png")
	{

		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setPosition(x + 25, y+ 40);
		sprite.setScale(0.35, 0.35);
	}

};
#endif