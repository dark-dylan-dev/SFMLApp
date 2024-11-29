 #ifndef GAME_H
 #define GAME_H

// ----- SFML ----- //
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
// ----- STL ----- //
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Game {
public:
	Game();

	void run();

private:
	bool m_isRunning;
	// Window & important application variables
	sf::RenderWindow* window;
	sf::WindowBase windowBase;
	sf::Event event;
	sf::Image appIcon;
	sf::Clock Clock;
	float f_ElapsedTime;
	// Sub-programs
	std::string mode = "default";
	bool showMenu = false;
	bool pongStarted = false;
	bool TBKStarted = false;
	// Time
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;
	float timeSinceLastCollision;
	const float minimalTimeBetweenCollisions = (1.f/10.f); // 10 collisions / second maxmimum

private:
	void initFonts();
	void initTextures();
	void initTexts();
	void pollEvents();
	void update();
	void render();
};

 #endif // !GAME_H