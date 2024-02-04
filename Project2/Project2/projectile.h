#pragma once

#include <SFML/Graphics.hpp>

class Projectile {
public:
    Projectile(float startX, float startY);
    void update(float deltaTime);
    const sf::CircleShape& getShape() const;
    sf::Vector2f getPosition() const;
    bool collidesWith(const sf::FloatRect& otherBounds) const;
    bool isMarkedForDestruction() const; // Ajout de la d�claration
    void markForDestruction(); // Ajout de la d�claration

private:
    sf::Vector2f position;
    float speed;
    sf::CircleShape shape;
    bool markedForDestruction;
};
