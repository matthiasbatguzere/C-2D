#include "enemy.h"

Enemy::Enemy(float startX, float startY)
    : position(startX, startY), speed(50.0f), isDestroyed(false) {
    shape.setRadius(20.0f);
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin(20.0f, 20.0f);
    shape.setPosition(position);
}

void Enemy::update(float deltaTime) {
    if (!isDestroyed) {  // Ne mettez à jour que si l'ennemi n'est pas détruit
        position.y += speed * deltaTime;
        shape.setPosition(position);
    }
}

const sf::CircleShape& Enemy::getShape() const {
    return shape;
}

sf::Vector2f Enemy::getPosition() const {
    return position;
}

void Enemy::markForDestruction() {
    isDestroyed = true;
}

bool Enemy::isMarkedForDestruction() const {
    return isDestroyed;
}
