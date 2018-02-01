#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"

////stateMachines structures
//MainMenu
//struct bMAINMENU
//{bool start,soundOn,exit,showOptions,showStory;};

//Story
//struct bSTORY
//{bool start,nextPage,End;};

//Game
//struct bGAME
//{bool start,Pause,End;};

class StateManager
{
    private:
        //MainMenu
        MainMenu *mainMenu;

        //StateMachine's
        //bMAINMENU *bMainMenu;bSTORY *bStory;bGAME *bGame;

    public:
        StateManager(sf::RenderWindow *window);
        void eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse);
        void renderManager(sf::RenderWindow *window);
        ~StateManager();
};
#endif
