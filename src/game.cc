#include "../inc/game.h"

#pragma region Constructors and Destructors

Game::Game() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete window;
}

#pragma endregion

#pragma region Accessors

const bool Game::running() const {
    return window->isOpen();
}

#pragma endregion

#pragma region Public Methods

void Game::update() {
    pollEvents();

    // TODO: Add update logic here
}

void Game::render() {
    window->clear(sf::Color::Black);

    // TODO: Add drawing code here

    window->display();
}

#pragma endregion

#pragma region Private Methods

void Game::initVariables() {
    window = nullptr;
}

void Game::initWindow() {
    videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

void Game::pollEvents() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
    }
}

#pragma endregion