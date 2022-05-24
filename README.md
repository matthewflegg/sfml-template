# SFML Project Template
This is a simple template for starting SFML projects.

## Guide
**[Installation](#installation)**

**[Compilation](#compilation)**
* [Adding Files](#adding-files-optional)
* [SFML Headers](#adding-files-optional)
* [Changing Folder Names](#changing-folder-names)

**[Game Class](#game-class)**
* [Class Members](#class-members)
* [Update and Draw](#update-and-draw)
* [Init Methods](#init-methods)
* [Accessors](#accessors)
* [Constructor and Destructor](#constructor-and-destructor)

## Installation
Simply run the following terminal commands:
```bash
git clone https://github.com/matthewflegg/sfml-template.git
cd sfml-template
```
You can also just create a template from the repository or clone this repo a different way. Regardless of how you do it, everything else will work the same way.

## Compilation
Compilation is done via a shell script. Unfortunately, I haven't got round to writing a script for Windows yet. On Linux or macOS, run the following commands:
```bash
chmod +x build.sh
./build.sh
```

To run your game, run:
```bash
./bin/game
```

#### Adding Files (Optional)
You should add header files in the `inc` directory. Place their corresponding source files in `src`.

When you add a new source file open `build.sh`. Add a new line to the `cpp` string. Here's an example:

Before:
```bash
cpp="\
     $root/$src/game.cc"
```
After:
```bash
cpp="\
     $root/$src/game.cc \
     $root/$src/enemy.cc"
```

You shouldn't include any header files in the script. For more information, read the comments, these outline the steps to compile the project.

#### SFML Headers (Optional)
You can remove any SFML headers that you haven't included. For instance, let's remove `SFML/Network.hpp`:

Before:
```bash
lib="\
     -lsfml-audio \
     -lsfml-graphics \
     -lsfml-network \
     -lsfml-system \
     -lsfml-window"
 ```
 
 After:
```bash
lib="\
     -lsfml-audio \
     -lsfml-graphics \
     -lsfml-system \
     -lsfml-window"
 ```
 
#### Changing Folder Names
If you change the names of any directories, make sure you change their corresponding variable in `build.sh`. For example, let's change `src` to `source` and `inc` to `include`:

Before:
```bash
src="src"
inc="inc"
```

After:
```bash
src="source"
inc="include"
```
 
## Game Class
The game class is relatively straightforward to use. It includes update and render methods, and well as a `sf::RenderWindow*` and `sf::VideoMode`. You shouldn't need to edit `main.cc`.

#### Class Members
The game class includes three private members. These are:

```cpp
sf::RenderWindow* window;  // Pointer to the render window used to draw to the screen
sf::VideoMode videoMode;   // Contains the resolution
sf::Event event;           // Used to store the value of events when `pollEvents` is called
```

#### Update and Draw
This is the same as most games you'll find. Just put your update logic in `update()`, and your drawing logic in `draw()`. 

```cpp
void Game::update() {
    pollEvents();

    // TODO: Add update logic here
}

void Game::render() {
    window->clear(sf::Color::Black);

    // TODO: Add drawing code here

    window->display();
}
```

#### Init Methods
Here you'll find methods to set up the window and other variables. The usual event polling code you'd find in an SFML project is placed within `pollEvents` for organisation.

```cpp
void Game::initVariables() {
    window = nullptr;  // It's always good to initialize your variables
}

void Game::initWindow() {
    // You can change the window settings here, such as the title and resolution
    videoMode = sf::VideoMode(800, 600);
    window = new sf::RenderWindow(videoMode, "Game", sf::Style::Titlebar | sf::Style::Close);
}

void Game::pollEvents() {
    // You can change or add events here, such as player input
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window->close();
    }
}
```

#### Accessors
Game has an accessor that returns a bool indicating if the window is open. This is used in `main.cc`.

```cpp
const bool Game::running() const {
    return window->isOpen();
}
```

#### Constructor and Destructor
Game also includes a constructor and destructor. Do **not** remove the `delete window` statement, as `window` is dynamically allocated.

```cpp
Game::Game() {
    initVariables();
    initWindow();
}

Game::~Game() {
    delete window;
}
```
