#ifndef GAME_H
#define GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

/**
 * @brief Wrapper class that acts as the game engine.
 *
 */
class Game {
   public:
    /**
     * @brief Construct a new Game object.
     *
     */
    Game();

    /**
     * @brief Destroy the Game object.
     *
     */
    ~Game();

    /**
     * @brief Contains the game's update logic.
     *
     */
    void update();

    /**
     * @brief Contains the game's drawing logic.
     *
     */
    void render();

    /**
     * @brief Indicates whether the game is running.
     *
     * @return true  The game window is open.
     * @return false The game window is closed.
     */
    const bool running() const;

   private:
    // Private variables
    sf::RenderWindow* window;
    sf::VideoMode videoMode;
    sf::Event event;

    // Private methods
    void initVariables();
    void initWindow();
    void pollEvents();
};

#endif