#include "enemy.h"

Enemy::Enemy(float startX, float startY)
    : position(startX, startY), speed(100.0f) {
    shape.setRadius(Width / 2); 
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Red); 
}

void Enemy::update(float deltaTime) {
    position.y += speed * deltaTime; 
    shape.setPosition(position);
}

const sf::CircleShape& Enemy::getShape() const {
    return shape;
}

sf::Vector2f Enemy::getPosition() const {
    return position;
}

bool Enemy::isMarkedForDestruction() const {
    return markedForDestruction;
}
void Enemy::markForDestruction() {
    markedForDestruction = true;
}