#include "Tank.h"

Tank::Tank(sf::RenderWindow *window)
{
    windowX=window->getSize().x; windowY=window->getSize().y;

    //Textures
    Tank_texture[0].loadFromFile("GameData/Tank01.png");
    Tank_texture[1].loadFromFile("GameData/Tank02.png");
    Tank_texture[2].loadFromFile("GameData/Tank03.png");
    Tank_texture[3].loadFromFile("GameData/Tank04.png");

    //Sprite
    for(int i=0;i<numOfTanks;i++)
    {
        Tank_sprite[i].setTexture(Tank_texture[i]);
        Tank_sprite[i].setPosition(0,0);
    }
}

void Tank::manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse)
{

}

void Tank::update(sf::RenderWindow *window,sf::Mouse *mouse)
{

}

void Tank::Display(sf::RenderWindow *window)
{
    for(int i=0;i<numOfTanks;i++)
    {window->draw(Tank_sprite[i]);}
}

Tank::~Tank()
{

}
