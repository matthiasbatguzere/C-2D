#include <SFML/Graphics.hpp>
#include "player.h"
#include "projectile.h"
#include "enemy.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders");

    Player player(400, 550, 200.0f);
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;
    sf::Clock clock;
    sf::Time lastFrameTime = sf::Time::Zero;

    int enemyRowCount = 5;
    int enemyColumnCount = 10;
    float enemySpacing = 50.0f;
    float startX = 100.0f;
    float startY = 100.0f;

    for (int row = 0; row < enemyRowCount; ++row) {
        for (int col = 0; col < enemyColumnCount; ++col) {
            float posX = startX + col * (Enemy::Width + enemySpacing);
            float posY = startY + row * (Enemy::Height + enemySpacing);
            enemies.emplace_back(posX, posY);
        }
    }

    while (window.isOpen()) {
        sf::Time currentTime = clock.getElapsedTime();
        sf::Time deltaTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.moveLeft(deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.moveRight(deltaTime.asSeconds());
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.shoot(currentTime);
        }

        for (auto& projectile : projectiles) {
            projectile.update(deltaTime.asSeconds());
        }

        projectiles.erase(std::remove_if(projectiles.begin(), projectiles.end(),
            [](const Projectile& projectile) { return projectile.isMarkedForDestruction(); }),
            projectiles.end());

        for (auto& projectile : projectiles) {
            for (auto& enemy : enemies) {
                if (projectile.collidesWith(enemy.getShape().getGlobalBounds())) {
                    enemy.markForDestruction();
                    projectile.markForDestruction();
                }
            }
        }

        enemies.erase(std::remove_if(enemies.begin(), enemies.end(),
            [](const Enemy& enemy) { return enemy.isMarkedForDestruction(); }),
            enemies.end());

        for (auto& enemy : enemies) {
            enemy.update(deltaTime.asSeconds());
        }

        window.clear();

        for (const auto& enemy : enemies) {
            window.draw(enemy.getShape());
        }

        for (const auto& projectile : projectiles) {
            window.draw(projectile.getShape());
        }

        sf::RectangleShape playerShape(sf::Vector2f(50.0f, 50.0f));
        playerShape.setPosition(player.getPosition());
        window.draw(playerShape);

        window.display();
    }

    return 0;
}
