#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Tank.h"

class StateManager
{
    private:
        //MainMenu
        MainMenu *mainMenu;
        Tank *tank;

        //States
        bool bMainMenu_state,bGameOn_state,bEndGame_state;

    public:
        StateManager(sf::RenderWindow *window);
        void eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse);
        void renderManager(sf::RenderWindow *window);
        ~StateManager();
};
#endif
