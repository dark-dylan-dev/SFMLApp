 #ifndef GAME_H
 #define GAME_H

// ----- SFML ----- //
#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"
// ----- STL ----- //
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <list>
#include <array>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

class Game {
public:
	Game();
	~Game();

	void run();

private:
	bool m_isRunning;
	bool cond = true;
	// Window & important application variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Image appIcon;
	sf::Clock Clock;
	float f_ElapsedTime; // Temps écoulé depuis la dernière frame
	// ----------------------------------- //
	const float m_topBarHeight = 30.f;
	bool showMenu = false;
	bool pongStarted = false;
	bool TBKStarted = false;
	bool TBKPaused = false;
	bool m_isMouseDragging;
	unsigned int m_lastDownX;
	unsigned int m_lastDownY;
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;

private:
	// --- Colors --- //
	std::array<sf::Color, 12> colors; // Colors of the DVD Logo
	// --- Tiles TBK --- //
	std::array<sf::RectangleShape, 70> tilesTbk; // Tiles in the tilebreaker game (7 height, 10 width -> 7x10 setup -> 70 tiles)
	std::array<sf::Text, 70> tilesLifesTbk;      // Their lifes ^^^
	bool tilesTbkState[70];                      // To get if a tile is broken or not
	int tileLife;
	int tileLifeTbk[70];
	// --- Textures --- //
	sf::Image brush;
	sf::Texture logoDVD;
	sf::Sprite sprLogoDVD;
	sf::Texture smallAppIcon;
	sf::Sprite smallAppIconSpr;
	sf::Texture closeWindowIcon;
	sf::Sprite closeWindowIconSpr;
	sf::Texture minimizeWindowIcon;
	sf::Sprite minimizeWindowIconSpr;
	// --- Fonts --- //
	sf::Font Impact, Arial, Comic, GoodTiming;
	// --- Texts "All modes" --- //
	std::string mode = "tilebreaker";
	sf::Text windowTitle;
	sf::Text FPString;
	sf::Text timeSinceStart;
	sf::Text menuTextOne;   // Fermer
	sf::Text menuTextTwo;   // Réduire
	sf::Text menuTextThree; // Peindre
	sf::Text menuTextFour;  // Effacer
	sf::Text menuTextFive;  // Pong
	sf::Text menuTextSix;   // Casse briques
	sf::Text menuTextSeven; // Megalovania
	// --- Texts "Pong" mode --- //
	sf::Text pongScoreLeftPlayer;
	sf::Text pongScoreRightPlayer;
	sf::Text pongControlsLeft;
	sf::Text pongControlsRight;
	// --- Texts "Tilebreaker" mode --- //
	sf::Text TBKTileHP;
	sf::Text TBKScore;
	// --- Shapes "all modes" --- //
	sf::RectangleShape CustomTitleBarBG;
	sf::RectangleShape windowBounds;
	sf::RectangleShape windowExitCross;
	sf::RectangleShape windowReduceLine;
	sf::RectangleShape menuBackground;
	sf::RectangleShape menuTextOneRect;
	sf::RectangleShape menuTextTwoRect;
	sf::RectangleShape menuTextThreeRect;
	sf::RectangleShape menuTextFourRect;
	sf::RectangleShape menuTextFiveRect;
	sf::RectangleShape menuTextSixRect;
	sf::RectangleShape menuTextSevenRect;
	sf::RectangleShape windowExitCrossRect;
	sf::RectangleShape windowReduceLineRect;
	// --- Shapes "paint" --- //
	sf::RectangleShape paintWhiteBoard;
	sf::RectangleShape paintTopBarPalette;
	sf::RectangleShape paintTopBarPaletteColorsSection;
	sf::RectangleShape paintTopBarPaletteColorsSectionOutline;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorWhite;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorRed;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorGreen;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorBlue;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorBlack;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorGray;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorOrange;
	sf::RectangleShape paintTopBarPaletteClearSection;
	sf::RectangleShape paintTopBarPaletteClearSectionOutline;
	sf::RectangleShape paintTopBarPaletteClearSectionElementOutline;
	sf::RectangleShape paintTopBarPaletteClearSectionEraser;
	sf::RectangleShape paintTopBarPaletteClearSectionClearAll;
	sf::RectangleShape paintTopBarPaletteThicknessChoice;
	sf::RectangleShape paintTopBarPaletteThicknessChoiceOutline;
	// --- Shapes "Pong" --- //
	sf::CircleShape pongPlayBall;
	sf::RectangleShape pongPlayerRacket;
	sf::RectangleShape pongOpponentRacket;
	sf::RectangleShape pongMiddleLine;
	sf::RectangleShape pongScoreBox;
	// --- Shapes "Tilebreaker" --- //
	// *TBK = Tilebreaker
	sf::RectangleShape TBKScene;
	sf::RectangleShape TBKTile;
	sf::RectangleShape TBKTileOutline;
	sf::RectangleShape TBKPaddle;
	sf::CircleShape TBKBall;
	// --- Music --- //
	sf::Music mus_megalovania; // \brief ...You're dead... \param You \param Sans
	sf::Music TBKTileBroken;

private:
	void initFonts();
	void initTextures();
	void initTexts();
	void pollEvents();
	void update();
	void render();
};

 #endif // !GAME_H