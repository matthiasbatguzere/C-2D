#pragma once

#include <SFML/Graphics.hpp>
#include "projectile.h"
#include <vector>

class Player {
public:
    Player(float startX, float startY, float playerSpeed);
    void update(float deltaTime);
    void moveLeft(float deltaTime);
    void moveRight(float deltaTime);
    void shoot(const sf::Time& currentTime);
    bool canShoot() const;
    const std::vector<Projectile>& getProjectiles() const;
    std::vector<Projectile>& getProjectiles();
    sf::Vector2f getPosition() const;

private:
    sf::Vector2f position;
    float speed;
    sf::Clock shotClock;
    std::vector<Projectile> projectiles;
};
