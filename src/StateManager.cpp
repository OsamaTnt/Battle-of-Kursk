#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow *window)
{
    //mainMenu
    mainMenu = new MainMenu(window);

    //StateMachine
    //bMainMenu=new bMAINMENU; bStory=new bSTORY; bGame=new bGAME;
    //bMainMenu->start=false; bMainMenu->soundOn=true;
    //bMainMenu->showOptions=bMainMenu->showStory=bMainMenu->exit=false;
    //bStory->start=bStory->nextPage=bStory->End=false;
    //bGame->start=bGame->Pause=bGame->End=false;
}

//event_manager
void StateManager::eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse)
{
    ////pollEvents
    //.....
    //...
    //.

    //mainMenu
    if(mainMenu)
    {mainMenu->manageEvents(event,window,mouse);}

}

//update
void StateManager::update(sf::RenderWindow *window,sf::Mouse *mouse)
{
    //updated everyFrame
    //...
    mainMenu->update(window,mouse);
}

//render_manager
void StateManager::renderManager(sf::RenderWindow *window)
{
    //mainMenu state
    if(mainMenu)
    {
        mainMenu->Display(window);
    }
}

StateManager::~StateManager()
{
    /*delete bMainMenu;
    delete bStory;
    delete bGame;*/
}
