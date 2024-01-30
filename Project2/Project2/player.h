#pragma once

#include <SFML/Graphics.hpp>
#include "projectile.h"
#include <vector>

class Player {
public:
    Player(float startX, float startY, float playerSpeed);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void shoot(const sf::Time& currentTime); 
    const std::vector<Projectile>& getProjectiles() const;
    std::vector<Projectile>& getProjectiles();
    sf::Vector2f getPosition() const;

private:
    sf::Vector2f position;
    float speed;
    std::vector<Projectile> projectiles;
    sf::Clock shotClock;
};
