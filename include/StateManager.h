#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Tank.h"
#include "EnemeyCastle.h"

class StateManager
{
    private:
        MainMenu *mainMenu;
        Tank *tank;
        EnemeyCastle *enemeyCastle;


        //States
        bool bMainMenu_state,bGameOn_state,bEndGame_state;

        //Test BackGround map
        sf::Sprite BackGround_shape;
        sf::Texture BackGround_texture;



        sf::String winner_string;
        sf::String lost_string;
        sf::Font font;
        sf::Text EndGame_text;

    public:
        StateManager(sf::RenderWindow *window);
        void eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse);
        void renderManager(sf::RenderWindow *window);
        ~StateManager();
};
#endif
