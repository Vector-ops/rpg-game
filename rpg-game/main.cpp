#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"
#include "FrameRate.h"
#include <iostream>



int main()
{
    // ------------------------------------------------INITIALIZE--------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "RPG Game", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    FrameRate frameRate;
    Player player;
    Skeleton skeleton;
    

    frameRate.Initialize();
    player.Initialize();
    skeleton.Initialize();


    
    frameRate.Load();
    player.Load();
    skeleton.Load();

    sf::Clock clock;


    // main game loop
    while (window.isOpen())
    {

        // delta time
        sf::Time deltaTimeTimer = clock.restart();
        double deltaTime = deltaTimeTimer.asMicroseconds() / 1000.0;
       

        //-------------------------------------------UPDATE--------------------------------------------
        sf::Event event;
        // event loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        frameRate.Update(deltaTime);
        player.Update(skeleton, deltaTime);
        skeleton.Update(deltaTime);

        //-------------------------------------------DRAW--------------------------------------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);
        
        window.display();
        
    }

    return 0;
}