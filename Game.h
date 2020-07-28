#include <SFML/Graphics.hpp>

#include <iostream> //std::cout for debugging atm

class Game{
    private:
        sf::RenderWindow window;
        void checkEvents();

    public:
        Game(sf::VideoMode videoMode/*, uint32_t windowSettings = sf::Style::Default*/);
        void run();
};