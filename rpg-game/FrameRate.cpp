#include "FrameRate.h"
#include <iostream>

FrameRate::FrameRate() : 
    timer(0)
{
}

FrameRate::~FrameRate()
{
}

void FrameRate::Initialize()
{
}

void FrameRate::Load()
{
    if (font.loadFromFile("Assets/Fonts/arial.ttf")) {
        std::cout << "Arial.ttf font loaded." << std::endl;
        frameRateText.setFont(font);
    }
    else {
        std::cout << "Failed to load font" << std::endl;
    }
}

void FrameRate::Update(double deltaTime)
{
    timer += deltaTime;
    if (timer >= 100.0) {
        double fps = 1000.0 / deltaTime;
        std::string frameRateString = "FPS: " + std::to_string((int)fps) + " frame time: " + std::to_string((int)deltaTime);
        frameRateText.setString(frameRateString);
        timer = 0;
    }
}

void FrameRate::Draw(sf::RenderWindow &window)
{
    window.draw(frameRateText);
}
