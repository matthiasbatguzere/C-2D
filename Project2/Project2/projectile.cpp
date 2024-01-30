#include "projectile.h"

Projectile::Projectile(float startX, float startY)
    : position(startX, startY), speed(500.0f) {
    shape.setRadius(5.0f);
    shape.setFillColor(sf::Color::White);
    shape.setOrigin(5.0f, 5.0f);
    shape.setPosition(position);
}

void Projectile::update(float deltaTime) {
    position.y -= speed * deltaTime;
    shape.setPosition(position);
}

sf::Vector2f Projectile::getPosition() const {
    return position;
}

const sf::CircleShape& Projectile::getShape() const {
    return shape;
}

bool Projectile::collidesWith(const sf::FloatRect& otherBounds) const {
    return shape.getGlobalBounds().intersects(otherBounds);
}

bool Projectile::isMarkedForDestruction() const {
  
    return false; 
}

void Projectile::markForDestruction() {
    
}
