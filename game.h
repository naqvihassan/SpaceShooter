
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include <time.h>
#include "menu.h"
#include "player.h"
#include "enemy.h"
#include "invader.h"
#include "alpha.h"
#include "Beta.h"
#include "Gama.h"
#include "Dragon.h"
#include "Monster.h"
#include "Fire.h"
#include "Danger.h"
#include "Life.h"
#include <iostream>
#include <iomanip>
using namespace std;
const char title[] = "OOP-Project, Spring-2023";
using namespace sf;

class Game
{

public:
    // sf::RenderWindow window;
    Menu menu;

    Sprite background; // Game background sprite
    Texture bg_texture;
    Player *P; // player
    // Add_F other game attributes
    int max_enemy = 10;
    Enemy *E[10];
    Enemy *D;
    Enemy *M;
    bool E_active[10];
    bool E_bomb[10];
    int Wave = 1;
    int Level = 1;
    int score = 0;
    Clock clock;
    Font font;

    AddOn *Add_F;
    AddOn *Add_D;
    AddOn *Add_L;
    AddOn *Add_P;

    Text scoreText;
    Text timerText;
    Text highestScoreText;
    Text LevelText;
    Text LifeText;

    float delay = 0;
    Game()
    {

        ////////////////////////--MY PLAYER--/////////////////////////

        P = new Player();
        if (Level == 1) // Rectangle
        {
            E[0] = new Alpha(300, 170);
            E[1] = new Alpha(500, 100);
            E[2] = new Alpha(400, 30);
            E[3] = new Beta(500, 30);
            E[4] = new Beta(300, 30);
            E[5] = new Beta(200, 170);
            E[6] = new Gama(200, 30);
            E[7] = new Gama(400, 170);
            E[8] = new Gama(500, 170);
            E[9] = new Gama(200, 100);
        }
        D = new Dragon();
        D->bomb_fire(360, 280);
        M = new Monster();
        M->bomb_move();
        ////////////////////////--AddOn--//////////////////////////
        Add_F = new Fire();
        Add_D = new Danger();
        Add_L = new Life();

        for (int i = 0; i < max_enemy; ++i)
        {
            E_active[i] = true;
            E_bomb[i] = false;
        }

        bg_texture.loadFromFile("img/background_5.png");
        background.setTexture(bg_texture);
        background.setScale(1.02, 1.03);

        // Score
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "Could not load font from file" << endl;
        }
    }

    bool checkCollision(const Sprite &spriteA, const Sprite &spriteB)
    {
        const float positionAX = spriteA.getPosition().x;
        const float positionAY = spriteA.getPosition().y;
        const float positionBX = spriteB.getPosition().x;
        const float positionBY = spriteB.getPosition().y;

        const float sizeAX = spriteA.getGlobalBounds().width;
        const float sizeAY = spriteA.getGlobalBounds().height;
        const float sizeBX = spriteB.getGlobalBounds().width;
        const float sizeBY = spriteB.getGlobalBounds().height;

        // Check for collision between the sprites
        if (positionAX < positionBX + sizeBX &&
            positionAX + sizeAX > positionBX &&
            positionAY < positionBY + sizeBY &&
            positionAY + sizeAY > positionBY)
        {
            return true; // Collision detected
        }

        return false; // No collision
    }

    void start_game()
    {

        // Call the display_menu function before creating the RenderWindow

        srand(time(0));
        float windowWidth = 780.0f;
        float windowHeight = 620.0f;
        RenderWindow window(VideoMode(900, 620), title);
        // Menu menu(windowWidth, windowHeight);
        // menu.display_menu();
        Clock clock;
        float timer = 0;

        bool dragon_check = false;
        float dragon_interval = 0;

        bool monster_fire = false;
        bool monster_check = false;
        float monster_interval = 0;
        bool right = true;
        bool left = false;

        float alpha_interval = 5.0;
        float beta_interval = 3.0;
        float gama_interval = 2.0;
        float last_bomb[max_enemy] = {0.0};

        bool level_check = false;

        bool menuOpen = true;

        bool AddOn = false;
        bool add_F_active = false;
        bool add_D_active = false;
        bool add_L_active = false;

        float A_fire_timer = 0;
        float A_danger_timer = 0;
        float A_life_timer = 0;

        bool fire_active = false;
        bool danger_active = false;
        bool life_active = false;
        bool check_danger = false;
        bool check_life = false;

        ///////////////////////////////////////////////////////////////////

        while (window.isOpen() && P->lives > 0 && Level < 3)
        {
            if (menuOpen)
            {
                menu.draw(window);
                menuOpen = false;
            }
            ////////////////////--Add On--///////////////////////////////

            if (!add_F_active)
            {
                if (rand() % 100 == 0)
                {
                    add_F_active = true;
                    Add_F->setAddOn(rand() % 680, 0);
                }
            }

            if (add_F_active)
            {
                Add_F->moveAddOn();
                if (Add_F->sprite.getPosition().y > 620)
                {
                    add_F_active = false;
                }
            }
            if (add_F_active)
            {
                if (checkCollision(P->sprite, Add_F->sprite))
                {
                    fire_active = true;
                    A_fire_timer = timer;
                }
                if ((int)timer - (int)A_fire_timer < 5)
                {
                    P->B->setFire();
                }
                else
                {
                    fire_active = false;
                    P->B->setnormalfire();
                }
            }
            if (!add_D_active)
            {
                if (rand() % 100 == 10) // danger
                {
                    add_D_active = true;
                    check_danger = true;
                    Add_D->setAddOn(rand() % 680, 0);
                }
            }
            if (add_D_active)
            {
                Add_D->moveAddOn();
                if (Add_D->sprite.getPosition().y > 620)
                {
                    add_D_active = false;
                }
            }
            if (!add_L_active)
            {
                if (rand() % 100 == 99)
                {
                    add_L_active = true;
                    check_life = true;
                    Add_L->setAddOn(rand() % 680, 0);
                }
            }
            if (add_L_active)
            {
                Add_L->moveAddOn();
                if (Add_L->sprite.getPosition().y > 620)
                {
                    add_L_active = false;
                }
            }
            if (add_L_active)
            {
                if (checkCollision(P->sprite, Add_L->sprite))
                {
                    life_active = true;
                    check_life = false;
                    ++P->lives;
                }
            }
            if (!check_life)
            {
                Add_L->sprite.setPosition(0, 900);
            }

            if (check_danger)
            {
                if (checkCollision(P->sprite, Add_D->sprite))
                {
                    danger_active = true;
                    check_danger = false;
                    --P->lives;
                }
            }
            if (!check_danger)
            {
                Add_L->sprite.setPosition(0, 900);
            }

            /////////////////--File Handling--/////////////////
            ifstream Highestfile("highscore.txt");

            Highestfile >> P->highestScore;

            Highestfile.close();
            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            Event e;

            bool check_img = true;

            scoreText.setFont(font);
            scoreText.setString("Score: " + to_string(P->score));
            scoreText.setCharacterSize(25);
            scoreText.setFillColor(Color::Black);
            scoreText.setPosition(740, 30);

            timerText.setFont(font);
            timerText.setString("Time(sec): " + to_string((int)timer));
            timerText.setCharacterSize(25);
            timerText.setFillColor(Color::Black);
            timerText.setPosition(740, 80);

            highestScoreText.setFont(font);
            highestScoreText.setString("Highest: " + to_string(P->highestScore));
            highestScoreText.setCharacterSize(25);
            highestScoreText.setFillColor(Color::Black);
            highestScoreText.setPosition(740, 130);

            LevelText.setFont(font);
            if (monster_check)
            {
                LevelText.setString("MONSTER!! ");
                LevelText.setCharacterSize(30);
            }
            else if (dragon_check)
            {
                LevelText.setString("DRAGON!! ");
                LevelText.setCharacterSize(30);
            }
            else
            {
                LevelText.setString("Level: " + to_string(Level));

                LevelText.setCharacterSize(25);
            }
            LevelText.setFillColor(Color::Black);
            LevelText.setPosition(740, 180);

            LifeText.setFont(font);
            LifeText.setString("Lives: " + to_string(P->lives));
            LifeText.setCharacterSize(30);
            LifeText.setFillColor(Color::Black);
            LifeText.setPosition(740, 230);

            /////////////////////////////--DRAGON--/////////////////////
            if (dragon_check)
            {
                if (P->sprite.getPosition().x > 460 && P->sprite.getPosition().y > 100)
                {
                    D->tiltedDragon(1);
                }
                else if (P->sprite.getPosition().x < 200 && P->sprite.getPosition().y > 100)
                {
                    D->tiltedDragon(2);
                }
                else
                    D->setDragon();
            }

            if (dragon_check == false && monster_check == false)
            {
                if (rand() % 100000 == 0)
                {
                    dragon_check = true;
                    dragon_interval = timer;
                }
            }
            if (dragon_check == true)
            {
                if ((int)timer - (int)dragon_interval == 6)
                {

                    dragon_check = false;
                    P->score += 50;
                    for (int i = 0; i < max_enemy; ++i)
                    {
                        if (E_bomb)
                            E[i]->bomb_fire(E[i]->sprite.getPosition().x, E[i]->sprite.getPosition().y); // TO appear enemy with bombs from starting point
                    }
                }
            }
            ///////////////////////////--MONSTER--/////////////////////////

            if (dragon_check == false && ((Level == 1 && Wave == 4) || (Level == 2 && Wave == 4)))
            {
                monster_check = true;
                monster_interval = timer;
                monster_fire = true;
                Wave++;
            }
            if (monster_check == true)
            {

                if (right)
                {
                    M->bomb_fire(1, 0);
                    if (M->sprite.getPosition().x > 450)
                    {
                        left = true;
                        right = false;
                    }
                }
                else if (left)
                {
                    M->bomb_fire(2, 0);
                    if (M->sprite.getPosition().x < 0)
                    {
                        right = true;
                        left = false;
                    }
                }
                if ((int)timer - (int)monster_interval > 3)
                {
                    monster_fire = false;
                    if ((int)timer - (int)monster_interval > 5)
                    {
                        monster_fire = true;
                    }
                    if ((int)timer - (int)monster_interval > 8)
                    {
                        monster_fire = false;
                    }
                    if ((int)timer - (int)monster_interval > 10)
                    {
                        monster_fire = true;
                    }
                    if ((int)timer - (int)monster_interval > 13)
                    {
                        P->score += 40;
                        monster_fire = false;
                        monster_check = false;
                        ++Level;
                        level_check = true;
                        //cout << Level << endl;
                    }
                }
            }

            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    window.close();          // close the game
            }

            // Input from user
            if (Keyboard::isKeyPressed(Keyboard::Left)) // If left key is pressed
            {
                P->move("l");
            }                                            // Player will move to left
            if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            {
                P->move("r");
            }                                         // player will move to right
            if (Keyboard::isKeyPressed(Keyboard::Up)) // If up key is pressed
            {
                P->move("u"); // player will move upwards
                if ((Keyboard::isKeyPressed(Keyboard::Right)))
                {
                    check_img = false;
                    if (!check_img)
                    {
                        P->setTiltedPlayerImage(1); // Tilted image will be displayed
                    }
                }
                if ((Keyboard::isKeyPressed(Keyboard::Left)))
                {
                    check_img = false;
                    if (!check_img)
                    {
                        P->setTiltedPlayerImage(2); // Tilted image will be displayed
                    }
                }
            }

            if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            {
                P->move("d");
                if ((Keyboard::isKeyPressed(Keyboard::Right)))
                {
                    check_img = false;
                    if (!check_img)
                    {
                        P->setTiltedPlayerImage(2); // Tilted image will be displayed
                    }
                }
                if ((Keyboard::isKeyPressed(Keyboard::Left)))
                {
                    check_img = false;
                    if (!check_img)
                    {
                        P->setTiltedPlayerImage(1); // Tilted image will be displayed
                    }
                }
            }
            if (check_img)
            {
                P->setPlayerImage();
            }

            if (Keyboard::isKeyPressed(Keyboard::Space))
            {

                P->setBullet();
            }
            // if (e.type == sf::Event::KeyReleased || e.type == sf::Event::KeyPressed)
            // {
            //     menu.handleEvents(window, e);
            // }

            ////////////////////////////////////////////////
            ///////  Call your functions here //////////////////////

            //////////////////////////////////////////////

            window.clear(Color::Black); // clears the screen
            window.draw(background);    // setting background
            window.draw(P->sprite);
            /////////////--CHECKING BULLET HIT ENEMY--//////////////////////
            for (int i = 0; i < 100; ++i)
            {
                for (int j = 0; j < max_enemy; ++j)
                {
                    if (checkCollision(P->B->sprite[i], E[j]->sprite))
                    {
                        E_active[j] = false;
                        if (fire_active)
                        {
                            //cout << "hello";
                        }
                        else
                            P->B->active_bullet[i] = false;
                        P->score += 10;
                        //cout << P->score << endl;
                    }
                }
            }
            P->B->bullet_update(window);

            /////////////////--BOMB--//////////////////////

            float interval = 0.0;
            for (int i = 0; i < max_enemy; ++i)
            {
                if (E_bomb[i])
                {
                    E[i]->bomb_move();
                    // last_bomb[i] += time;
                }
                if (!E_bomb[i])
                {
                    // cout << "1"<<endl;
                    E[i]->bomb_fire(E[i]->sprite.getPosition().x, E[i]->sprite.getPosition().y);
                    E_bomb[i] = true;
                    last_bomb[i] = timer;
                }
                if (i < 3)
                {
                    interval = alpha_interval;
                }
                else if (i < 6)
                {
                    interval = beta_interval;
                }
                else if (i < 9)
                {
                    interval = gama_interval;
                }
                if (timer - last_bomb[i] >= interval)
                {
                    E_bomb[i] = false;
                }
                if (E[i]->b->sprite.getPosition().y > 620)
                {
                    E_bomb[i] = false;
                }
            }
            // setting player on screen

            window.draw(scoreText);
            window.draw(timerText);
            window.draw(highestScoreText);
            window.draw(LevelText);
            window.draw(LifeText);

            window.draw(Add_F->sprite);
            window.draw(Add_D->sprite);
            window.draw(Add_L->sprite);
            ///////////////////////--LEVEL1--Wave2-- /////////////////////

            if (Level == 1 && Wave == 2) // Triangle
            {
                if (timer - delay < 2)
                {
                }
                else
                {

                    E[1]->sprite.setPosition(300, 100);
                    E[0]->sprite.setPosition(350, 30);
                    E[2]->sprite.setPosition(400, 100);
                    E[3]->sprite.setPosition(250, 170);
                    E[4]->sprite.setPosition(450, 170);
                    E[5]->sprite.setPosition(200, 240);
                    E[6]->sprite.setPosition(275, 240);
                    E[7]->sprite.setPosition(350, 240);
                    E[8]->sprite.setPosition(425, 240);
                    E[9]->sprite.setPosition(500, 240);
                }
            }

            ///////////////////////--Wave3-- /////////////////////

            if (Level == 1 && Wave == 3) // Cross
            {
                if (timer - delay < 2)
                {
                }
                else
                {
                    E[0]->sprite.setPosition(250, 30);
                    E[1]->sprite.setPosition(500, 30);
                    E[2]->sprite.setPosition(300, 90);
                    E[3]->sprite.setPosition(450, 90);
                    E[4]->sprite.setPosition(375, 150);
                    E[5]->sprite.setPosition(375, 150);
                    E[6]->sprite.setPosition(300, 210);
                    E[7]->sprite.setPosition(450, 210);
                    E[8]->sprite.setPosition(250, 270);
                    E[9]->sprite.setPosition(500, 270);
                }
            }
            ////////////////////--Level2--WAVE1--//////////////////////////////////
            if (level_check)
            {

                if (Level == 2) // Circle
                {
                    if (timer - delay < 2)
                    {
                    }
                    else
                    {
                        E[0]->sprite.setPosition(400, 30);
                        E[1]->sprite.setPosition(475, 75);
                        E[2]->sprite.setPosition(550, 150);
                        E[3]->sprite.setPosition(325, 75);
                        E[4]->sprite.setPosition(550, 250);
                        E[5]->sprite.setPosition(475, 325);
                        E[6]->sprite.setPosition(400, 380);
                        E[7]->sprite.setPosition(325, 325);
                        E[8]->sprite.setPosition(250, 250);
                        E[9]->sprite.setPosition(250, 150);
                        Wave = 1;
                        level_check = false;
                    }
                }
            }
            ///////////////////////--Wave2-- /////////////////////
            if (Level == 2 && Wave == 2) // Diamond
            {
                E[0]->sprite.setPosition(400, 20);
                E[1]->sprite.setPosition(325, 75);
                E[2]->sprite.setPosition(475, 75);
                E[3]->sprite.setPosition(250, 150);
                E[4]->sprite.setPosition(550, 150);
                E[5]->sprite.setPosition(305, 225);
                E[6]->sprite.setPosition(495, 225);
                E[7]->sprite.setPosition(400, 375);
                E[8]->sprite.setPosition(335, 300);
                E[9]->sprite.setPosition(465, 300);
            }

            ///////////////////////--Wave3-- /////////////////////
            if (Level == 2 && Wave == 3) // Heart
            {
                E[0]->sprite.setPosition(350, 320); // Top center/
                E[1]->sprite.setPosition(325, 20);  // Upper left
                E[2]->sprite.setPosition(475, 20);  // Upper right
                E[3]->sprite.setPosition(225, 120); // Bottom left
                E[4]->sprite.setPosition(400, 120); // Bottom center
                E[5]->sprite.setPosition(575, 120); // Bottom right
                E[6]->sprite.setPosition(275, 220); // Bottom left
                E[7]->sprite.setPosition(450, 320); // Bottom center
                E[8]->sprite.setPosition(525, 220); // Bottom right
                E[9]->sprite.setPosition(400, 420); // Tail
            }

            if (!dragon_check && !monster_check)
            {
                for (int i = 0; i < max_enemy; ++i)
                {

                    if (checkCollision(P->sprite, E[i]->b->sprite)) // check for Player and enemy bomb
                    {
                        P->lives = P->lives - 1;
                        P->sprite.setPosition(340, 520);
                        cout << P->lives << endl;
                        E_bomb[i] = false;
                    }
                    if (E_active[i] == true)
                    { // cout <<i;
                        window.draw(E[i]->sprite);
                    }
                    else
                    {
                        // cout <<"a";
                        E[i]->sprite.setPosition(-100, -100);
                    }
                    if (E_active[i] == true)
                    {
                        window.draw(E[i]->sprite);
                    }
                    else
                    {
                        // cout <<"B"<<endl;
                        E[i]->sprite.setPosition(-100, -100);
                    }
                    if (E_bomb[i] == true)
                    {
                        window.draw(E[i]->b->sprite);
                    }
                    if (checkCollision(P->sprite, E[i]->sprite)) // check for player and enemy
                    {
                        P->lives = P->lives - 1;
                        P->sprite.setPosition(340, 520);
                        cout << P->lives << endl;
                    }
                }
            }
            if (dragon_check)
            {
                if (timer - delay < 1)
                {
                    // delay in fire
                }
                else
                {

                    if (checkCollision(P->sprite, D->sprite))
                    {
                        P->lives = P->lives - 1;
                        P->sprite.setPosition(340, 520);
                        cout << P->lives << endl;
                    }
                    else if (checkCollision(P->sprite, D->sprite1))
                    {
                        P->lives = P->lives - 1;
                        P->sprite.setPosition(P->sprite.getPosition().x + 100, 520);
                        cout << P->lives << endl;
                    }
                    window.draw(D->sprite1);
                }
                window.draw(D->sprite);
            }
            ///////////////////////////--MONSTER--////////////////////////
            if (monster_check)
            {
                if (checkCollision(P->sprite, M->sprite))
                {
                    P->lives = P->lives - 1;
                    P->sprite.setPosition(340, 520);
                    cout << P->lives << endl;
                }
                if (monster_fire)
                {
                    if (checkCollision(P->sprite, M->sprite1))
                    {

                        P->lives = P->lives - 1;
                        P->sprite.setPosition(P->sprite.getPosition().x + 100, 520);
                        cout << P->lives << endl;

                    }
                }

                if (monster_fire)
                    window.draw(M->sprite1);

                window.draw(M->sprite);
            }
            window.display(); // Displying all the sprites
            //////////////////////--Next Wave--/////////////////////////////

            int wave_check = 0;
            for (int i = 0; i < max_enemy; ++i)
            {
                if (E_active[i] == false)
                {
                    ++wave_check;
                }
            }
            if (wave_check == max_enemy)
            {
                ++Wave;
                cout << "Wave" << Wave << endl;
                wave_check = 0;

                for (int j = 0; j < max_enemy; ++j)
                {
                    E_active[j] = true;
                    P->B->active_bullet[j] = true;
                    delay = timer;
                }
            }
        }
        ofstream ScoreFile("scores.txt", ios::app);
        // write score to file
        if (ScoreFile.fail())
        {
            cout << "error";
        }
        else
        {
            // file write was successful
            ScoreFile << P->score << endl;
        }
        ScoreFile.close();
        // Save the score to the file
        ofstream HighestScoreFile("highscore.txt", ios::app);
        if (HighestScoreFile.is_open())
        {
            if (P->score > P->highestScore)
            {
                P->highestScore = P->score;
                HighestScoreFile << P->highestScore << endl;
            }
        }
        HighestScoreFile.close();

    }
    ~Game()
    {
        if (P != nullptr)
        {
            delete P;
        }
        if (E != nullptr)
        {
            for (int i = 0; i < 10; ++i)
            {
                if (E[i] != nullptr)
                {
                    delete E[i];
                }
            }
        }
        if (D != nullptr)
        {
            delete D;
        }
    }
};
#endif // GAME_H