#ifndef TANK_H
#define TANK_H
#include <iostream>
#include <SFML/Graphics.hpp>

const int numOfTanks = 4;

class Tank
{
    private:
        float windowX,windowY;

        sf::Texture Tank_texture[numOfTanks];
        sf::Sprite Tank_sprite[numOfTanks];


        int CurrentTankIndex;
        bool bStartMouseHovering,bMouseOnTank;

    public:
        Tank(sf::RenderWindow *window);
        void manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse);
        void update(sf::RenderWindow *window,sf::Mouse *mouse);
        void Display(sf::RenderWindow *window);
        ~Tank();
};

#endif // TANK_H
