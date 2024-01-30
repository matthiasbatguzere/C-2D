#include "player.h"

Player::Player(float startX, float startY, float playerSpeed)
    : position(startX, startY), speed(playerSpeed) {}

void Player::moveLeft(float deltaTime) {
    position.x -= speed * deltaTime;
    if (position.x < 0) {
        position.x = 0;
    }
}

void Player::moveRight(float deltaTime) {
    position.x += speed * deltaTime;
    float maxWidth = 800.0f;
    if (position.x > maxWidth) {
        position.x = maxWidth;
    }
}

void Player::shoot(const sf::Time& currentTime) {
    sf::Time elapsedTime = shotClock.getElapsedTime();
    if (elapsedTime >= sf::seconds(1.0)) {
        projectiles.push_back(Projectile(position.x, position.y));
        shotClock.restart();
    }
}

const std::vector<Projectile>& Player::getProjectiles() const {
    return projectiles;
}

std::vector<Projectile>& Player::getProjectiles() {
    return projectiles;
}

sf::Vector2f Player::getPosition() const {
    return position;
}
