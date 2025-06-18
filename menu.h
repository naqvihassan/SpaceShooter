
#ifndef MENU_H
#define MENU_H
#include <time.h>
#include "menu.h"
#include <iostream>
#include <iomanip>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

const char tit[] = "OOP-Project, Spring-2023";
class Menu
{

public:
    int index;
    Font font;
    Text menu_text[3];
    int menu_item=3;
    int current_item = 0;
    Menu()
    {
        SetMenu();
    }
    void SetMenu()
    {
        if (!font.loadFromFile("arial.ttf"))
        {
            cout << "Could not load font from file" << endl;
        }
        menu_text[0].setFont(font);
        // menu_text[0].setColor(Color :: Red );
        menu_text[0].setString("Play");
        menu_text[0].setPosition(220, 400);

        menu_text[1].setFont(font);
        // menu_text[1].setColor(Color :: White );
        menu_text[1].setString("Options");
        menu_text[1].setPosition(220, 200);

        menu_text[2].setFont(font);
        // menu_text[2].setColor(Color :: White );
        menu_text[2].setString("Exit");
        menu_text[2].setPosition(220, 600);
    }
    void draw(RenderWindow &window)
    {
        for (int i = 0; i < 3; ++i)
        {
            window.draw(menu_text[i]);
        }
        
        window.display();
        cout << "1";
    }
    // void handleEvents(RenderWindow &window, Event event)
    // {
    //     Event event;
    //     while (window.pollEvent(event))
    //     {
    //         switch (event.type)
    //         {
    //         case Event::Closed:
    //             window.close();
    //             break;
    //         case Event::KeyPressed:
    //             if (event.key.code == Keyboard::Escape)
    //             {
    //                 window.close();
    //             }
    //             else if (event.key.code == Keyboard::Up)
    //             {
    //                 if (menu.index > 0)
    //                 {
    //                     event.index--;
    //                 }
    //             }
    //             else if (event.key.code == Keyboard::Down)
    //             {
    //                 if (event.index < 2)
    //                 {
    //                     event.index++;
    //                 }
    //             }
    //             else if (event.key.code == Keyboard::Enter)
    //             {
    //                 // Handle event item selection based on the index
    //                 switch (current_item)
    //                 {
    //                 case 0:
    //                     // Play selected
    //                     cout << "Play selected" << endl;
    //                     break;
    //                 case 1:
    //                     // Options selected
    //                     cout << "Options selected" << endl;
    //                     break;
    //                 case 2:
    //                     // Exit selected
    //                     window.close();
    //                     break;
    //                 }
    //             }
    //             break;
    //         }
    //     }
    // }

    // void moveUp();
    // void moveDown();
    // void display_menu()
    // {
    //     RenderWindow window(VideoMode(780, 620), tit);
    //         Event event;
    //         while (window.pollEvent(event))
    //         {
    //             cout <<"A";
    //             if (event.type == sf::Event::Closed)
    //             {
    //                 window.close();
    //                 return;
    //             }
    //             else if (event.type == sf::Event::KeyPressed)
    //             {
    //                 if (event.key.code == sf::Keyboard::S)
    //                 {
    //                     window.close();
    //                     return;
    //                 }
    //             }
    //         }
    //         window.clear();
    //         for (int i = 0; i < 3; ++i)
    //         window.draw(menu_text[i]);
    //         window.display();
    //     //}
    // }
    //~Menu() {}
};
#endif