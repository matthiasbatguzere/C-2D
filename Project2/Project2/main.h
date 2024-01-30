#include <SFML/Graphics.hpp>
#include "player.h"

class Game {
public:
    Game();
    void run();

private:
    sf::RenderWindow window;
    Player player;
};

int main();
