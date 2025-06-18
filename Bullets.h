#ifndef BULLETS_H
#define BULLETS_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
using namespace std;
using namespace sf;

class Bullet
{
public:
    Texture tex;
    Sprite sprite[100];
    int i = 0;              // bullet counter
    Clock bullet_timer;     // bullet timer
    float fire_rate = 0.2f; // Fire one bullet every half second
    float speed = 15.0f;    // Bullet speed
    // int x,y;
    bool active_bullet[100];


    Bullet(std::string png_path)
    {
        tex.loadFromFile(png_path);
    }

    void fire(int x_coordinate, int y_coordinate)
    {
        sprite[i].setTexture(tex);
        sprite[i].setPosition(x_coordinate + 32, y_coordinate - 30);
        sprite[i].setScale(0.30, 0.30);
        i++;
        if (i > 99)
        {
            i = 0;
        }
        active_bullet[i] = true;
    }

    void bullet_update(RenderWindow &window)
    {
        for (int i = 0; i < 100; i++)
        {
            if(active_bullet[i]){
                sprite[i].move(0, -1);
                window.draw(sprite[i]);
            }
            if(!active_bullet[i]){
                sprite[i].setPosition(-200,-200);
            }
        }
    }
    void setFire(){
        tex.loadFromFile("img/PNG/Lasers/laserRed08.png");
    }
    void setnormalfire(){
        tex.loadFromFile("img/PNG/Lasers/laserBlue08.png");

    }

};
#endif