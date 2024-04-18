#include <SFML/Graphics.hpp>

#include "Map.h"
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

    Map map;
    FrameRate frameRate;
    Player player;
    Skeleton skeleton;
    

    map.Initialize();
    frameRate.Initialize();
    player.Initialize();
    skeleton.Initialize();


    map.Load();
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

        sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        map.Update(deltaTime);
        frameRate.Update(deltaTime);
        player.Update(skeleton, deltaTime, mousePosition);
        skeleton.Update(deltaTime);

        //-------------------------------------------DRAW--------------------------------------------
        window.clear(sf::Color::Black);
        map.Draw(window);
        player.Draw(window);
        skeleton.Draw(window);
        frameRate.Draw(window);
        
        window.display();
        
    }

    return 0;
}