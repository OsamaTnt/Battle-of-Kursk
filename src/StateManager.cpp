#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow *window)
{
    //mainMenu
    mainMenu = new MainMenu(window);
    tank = new Tank(window);

    bMainMenu_state = true;
    bGameOn_state = false;
}

//event_manager
void StateManager::eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse)
{
    ///pollEvents
    //mainMenu
    if(mainMenu && bMainMenu_state) {mainMenu->manageEvents(event,window,mouse);}

    //tank
    if(tank && bGameOn_state) {tank->manageEvents(event,window,mouse);}
}

//update
void StateManager::update(sf::RenderWindow *window,sf::Mouse *mouse)
{
    ///updated everyFrame
    //update states
    bMainMenu_state = !mainMenu->isGameStarts();
    bGameOn_state = mainMenu->isGameStarts();

    //mainMenu
    if(mainMenu && bMainMenu_state) {mainMenu->update(window,mouse);}

    //tank
    if(tank && bGameOn_state) {tank->update(window,mouse);}
}

//render_manager
void StateManager::renderManager(sf::RenderWindow *window)
{
    //mainMenu state
    if(mainMenu && bMainMenu_state) { mainMenu->Display(window); }

    //tank state
    if(tank && bGameOn_state) { tank->Display(window); }
}

StateManager::~StateManager()
{
}
