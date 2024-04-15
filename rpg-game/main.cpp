#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Skeleton.h"



int main()
{
    // ------------------------------------------------INITIALIZE--------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "RPG Game", sf::Style::Default, settings);

    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();

    player.Load();
    skeleton.Load();

    // ------------------------------------------------INITIALIZE--------------------------------------------

    // main game loop
    while (window.isOpen())
    {
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

        player.Update(skeleton);
        skeleton.Update();

        //-------------------------------------------UPDATE--------------------------------------------
        //-------------------------------------------DRAW--------------------------------------------
        window.clear(sf::Color::Black);
        player.Draw(window);
        skeleton.Draw(window);
        window.draw(player.sprite);
        window.draw(skeleton.sprite);
        
        window.display();
        //-------------------------------------------DRAW--------------------------------------------
    }

    return 0;
}