#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow *window)
{
    windowX=window->getSize().x; windowY=window->getSize().y;

    bStart=bExit=bShowOptions=bShowStory=false;
    bSoundOn=true;
    bStartMouseHovering=false;bMouseOnItem=false;
    buttonCounter=0;

    //BG Image
    BG=new Image;
    BG->texture.loadFromFile("GameData/menuBG02.png");
    BG->Size={windowX,windowY};
    BG->shape.setTexture(&BG->texture);
    BG->shape.setPosition(0,0);
    BG->shape.setSize(BG->Size);

    //Font
    font.loadFromFile("GameData/BerkshireSwash-Regular.ttf");

    //MenuItems
    menuItem = new MenuItem[NumOfMenuItems];
    menuCurrentIndex = 0;

    menuItem[0].text.setString("StartGame");
    menuItem[1].text.setString("Music OFF");
    menuItem[2].text.setString("Show Story");
    menuItem[3].text.setString("Credits");
    menuItem[4].text.setString("Exit");

    for(int i=0;i<NumOfMenuItems;i++)
    {
        menuItem[i].text.setFont(font);
        menuItem[i].text.setCharacterSize(36);
        menuItem[i].text.setFillColor(sf::Color(45,0,0));
        if(i==0){menuItem[i].text.setPosition((windowX/2)-menuItem[i].text.getLocalBounds().width/2,windowY/1.645);}
        else if(i>0) {menuItem[i].text.setPosition((windowX/2)-menuItem[i].text.getLocalBounds().width/2,menuItem[i-1].text.getPosition().y+50);}
    }

    menuItem[menuCurrentIndex].text.setFillColor(sf::Color(255,40,15));

}

void MainMenu::manageEvents(sf::Event *event,sf::RenderWindow *window,sf::Mouse *mouse)
{
    ////Mouse controll
    for(int i=0;i<NumOfMenuItems;i++)
    {
        if(mouse->getPosition(*window).x > menuItem[i].text.getGlobalBounds().left&&mouse->getPosition(*window).x <= menuItem[i].text.getGlobalBounds().left+menuItem[i].text.getLocalBounds().width
         &&mouse->getPosition(*window).y >= menuItem[i].text.getGlobalBounds().top&&mouse->getPosition(*window).y < menuItem[i].text.getGlobalBounds().top+menuItem[i].text.getLocalBounds().height)
        {bStartMouseHovering=true;menuCurrentIndex=i;menuItem[menuCurrentIndex].text.setFillColor(sf::Color(255,40,15));bMouseOnItem=true;}
        else if(bStartMouseHovering){menuItem[i].text.setFillColor(sf::Color(45,0,0));}
    }

        //When enter is pressed
        if(mouse->isButtonPressed(sf::Mouse::Left) && bMouseOnItem)
        {
            if(menuCurrentIndex == NumOfMenuItems-1){bExit=true;}
            if(menuCurrentIndex == 0){bStart=true;}
            if(menuCurrentIndex == 1)
            {
                buttonCounter++;
                if(buttonCounter%2==0)
                {
                    bSoundOn=true;
                    menuItem[menuCurrentIndex].text.setString("Music OFF");
                    menuItem[menuCurrentIndex].text.setPosition((windowX/2)-menuItem[menuCurrentIndex].text.getLocalBounds().width/2,menuItem[menuCurrentIndex-1].text.getPosition().y+50);
                }else
                {
                    bSoundOn=false;
                    menuItem[menuCurrentIndex].text.setString("Music ON");
                    menuItem[menuCurrentIndex].text.setPosition((windowX/2)-menuItem[menuCurrentIndex].text.getLocalBounds().width/2,menuItem[menuCurrentIndex-1].text.getPosition().y+50);
                }
            }

            if(menuCurrentIndex == 2){}
            if(menuCurrentIndex == 3){}
        }
}

void MainMenu::update(sf::RenderWindow *window,sf::Mouse *mouse)
{
    if(bExit){window->close();}
}

bool MainMenu::isGameStarts()
{
    return bStart;
}

void MainMenu::Display(sf::RenderWindow *window)
{
    window->draw(BG->shape);

    for(int i=0;i<NumOfMenuItems;i++)
    {window->draw(menuItem[i].text);}

}

MainMenu::~MainMenu()
{
    delete BG;
}
