#include <iostream>
#include <SFML/Graphics.hpp>
#include "StateManager.h"

const float WIDTH = 1366,HIEGHT = 768;

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH,HIEGHT),"KURSK WAR",sf::Style::Default);
    window.setFramerateLimit(60);

    //state_manager object
    StateManager *state_manager = new StateManager(&window);

    sf::Event *event = new sf::Event;
    sf::Mouse *mouse = new sf::Mouse;

    while(true)
    {
        //pollEvents
        while(window.pollEvent(*event))
        {
            //Enable close window when pressing "x" icon
            if(event->type == sf::Event::Closed) {window.close();}
            state_manager->eventManager(&window,event,mouse);
        }

        //updated everyFrame
        state_manager->update(&window,mouse);

        window.clear();
        state_manager->renderManager(&window);
        window.display();

    }

    return 0;
}
