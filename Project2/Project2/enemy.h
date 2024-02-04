#pragma once

#include <SFML/Graphics.hpp>

class Enemy {
public:
    static constexpr float Width = 50.0f;
    static constexpr float Height = 50.0f;

    Enemy(float startX, float startY);
    void update(float deltaTime);
    const sf::CircleShape& getShape() const;
    sf::Vector2f getPosition() const;
    void markForDestruction();  // Ajout de la méthode
    bool isMarkedForDestruction() const;

private:
    sf::Vector2f position;
    float speed;
    sf::CircleShape shape;
    bool isDestroyed;  // Nouvelle variable
};
