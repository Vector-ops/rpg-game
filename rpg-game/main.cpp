#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"
#include <iostream>



int main()
{
    // ------------------------------------------------INITIALIZE--------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "RPG Game", sf::Style::Default, settings);
    window.setVerticalSyncEnabled(true);

    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();

    player.Load();
    skeleton.Load();

    sf::Clock clock;


    // main game loop
    while (window.isOpen())
    {

        // delta time
        sf::Time deltaTimeTimer = clock.restart();
        float deltaTime = deltaTimeTimer.asMilliseconds();


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


        player.Update(skeleton, deltaTime);
        skeleton.Update(deltaTime);

        //-------------------------------------------DRAW--------------------------------------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        window.draw(player.sprite);
        window.draw(skeleton.sprite);
        
        window.display();
        
    }

    return 0;
}