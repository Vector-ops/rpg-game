#include <SFML/Graphics.hpp>

int main()
{
    // ------------------------------------------------INITIALIZE--------------------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

    sf::CircleShape shape(50.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(sf::Vector2f(100, 100));
    shape.setOutlineThickness(10);
    shape.setOutlineColor(sf::Color::Blue);

    sf::RectangleShape rect(sf::Vector2f(50.f, 100.f));
    rect.setFillColor(sf::Color::Green);
    rect.setPosition(sf::Vector2f(200.f, 200.f));
    rect.setOrigin(rect.getSize() / 2.f);
    rect.setRotation(45.f);

    sf::CircleShape poly(50.f, 10);


    // ------------------------------------------------INITIALIZE--------------------------------------------

    while (window.isOpen())
    {
        //-------------------------------------------Update--------------------------------------------
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        //-------------------------------------------Update--------------------------------------------
        //-------------------------------------------Draw--------------------------------------------
        window.clear(sf::Color::Black);
        window.draw(shape);
        window.draw(rect);
        window.draw(poly);
        window.display();
        //-------------------------------------------Draw--------------------------------------------
    }

    return 0;
}