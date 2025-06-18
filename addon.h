#ifndef ADDON_H
#define ADDON_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include "enemy.h"
using namespace sf;
using namespace std;
class AddOn
{
public:
    Texture tex;
    Sprite sprite;
    Clock add_timer;
    float drop_rate = 0.2f;
    float speed = 1.01f;

    AddOn() {}
    AddOn(string png_path)
    {
        tex.loadFromFile(png_path);
        sprite.setTexture(tex);
        sprite.setPosition(0, -100);
        sprite.setScale(0.5, 0.5);
    }
    void setAddOn(int x, int y = 0)
    {
        sprite.setPosition(x,y);
    }
    void moveAddOn()
    {
        sprite.move(0, 1);
    }
};

#endif