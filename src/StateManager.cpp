#include "StateManager.h"

StateManager::StateManager(sf::RenderWindow *window)
{
    //mainMenu
    enemeyCastle = new EnemeyCastle(window);
    mainMenu = new MainMenu(window);
    tank = new Tank(window,enemeyCastle->Castle_position,enemeyCastle->Castle_Size);

    bMainMenu_state = true;
    bGameOn_state = false;

    //BackGround map
    BackGround_texture.loadFromFile("GameData/SnowMap.png");
    BackGround_shape.setTexture(BackGround_texture);
    BackGround_shape.setPosition(0,0);

    //EndGame Text
    winner_string = "You Won The Game!!";
    lost_string = "GameOver";

    font.loadFromFile("GameData/BerkshireSwash-Regular.ttf");
    EndGame_text.setFont(font);
    EndGame_text.setCharacterSize(50);
    EndGame_text.setFillColor(sf::Color::Red);



}

//event_manager
void StateManager::eventManager(sf::RenderWindow *window,sf::Event *event,sf::Mouse *mouse)
{
    ///pollEvents
    //mainMenu
    if(mainMenu && bMainMenu_state) {mainMenu->manageEvents(event,window,mouse);}

    //tank
    if(tank && bGameOn_state && tank->getNumOfDestroyedEnemys()<7) {tank->manageEvents(event,window,mouse);}
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
    if(tank && bGameOn_state) {tank->update(window,mouse,enemeyCastle);}

    ///check if numOfDestroyedEnemys >7 if true we won the game
    if(tank->getNumOfDestroyedEnemys() >=7)
    {
        for(int i=0;i<numOfTanks;i++)
        {
            tank->Hitler_militaryTank[i].bMoveForward=tank->Hitler_militaryTank[i].bMoveBackward=false;
            tank->Hitler_militaryTank[i].bMoveRight=tank->Hitler_militaryTank[i].bMoveLeft=false;
        }

        //set the end game text
        EndGame_text.setString(winner_string);
        EndGame_text.setPosition(window->getSize().x/2-EndGame_text.getLocalBounds().width/2,window->getSize().y/2-EndGame_text.getLocalBounds().height/2);

    }

}

//render_manager
void StateManager::renderManager(sf::RenderWindow *window)
{
    //BackGround Image Test
    window->draw(BackGround_shape);

    //mainMenu state
    if(mainMenu && bMainMenu_state) { mainMenu->Display(window); }

    //tank state
    if(tank && bGameOn_state) { tank->Display(window); enemeyCastle->Display(window);}

    if(tank && bGameOn_state && tank->getNumOfDestroyedEnemys()>=7)
    {
        window->draw(EndGame_text);
    }

}

StateManager::~StateManager()
{
}
