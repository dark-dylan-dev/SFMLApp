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

public:
	int lineThickness = 1;
	float drawRadius = 10.f;

private:
	bool m_isRunning;
	bool cond = true;
	// Window & important application variables
	sf::RenderWindow* window;
	sf::WindowBase windowBase;
	sf::Event event;
	sf::Image appIcon;
	sf::Clock Clock;
	float f_ElapsedTime; // Temps écoulé depuis la dernière frame
	// ----------------------------------- //
	const float m_topBarHeight = 30.f;
	bool showMenu = false;
	bool pongStarted = false;
	bool TBKStarted = false; /* TBK = TileBreaker */
	bool TBKPaused = false;
	bool m_isMouseDragging;
	unsigned int m_lastDownX;
	unsigned int m_lastDownY;
	std::chrono::steady_clock::time_point startingTimePoint, currentTimePoint;

private:
	// --- Cursors --- //
	sf::Cursor arrowCursor;
	sf::Cursor handCursor;
	// --- Colors --- //
	std::array<sf::Color, 12> colors; // Colors of the DVD Logo
	sf::Color lineColor = sf::Color(0,0,0); // Initialized to black
	// --- Tiles TBK --- //
	std::array<sf::RectangleShape, 70> tilesTbk; // Tiles in the tilebreaker game (7 height, 10 width -> 7x10 setup -> 70 tiles)
	std::array<sf::Text, 70> tilesLifesTbk;
	bool tilesTbkState[70];
	int tileLifeTbk[70];
	int tileLife;
	// --- Paint --- //
	bool isDrawingBrush = false;
	bool isDrawingPen = false;
	bool isErasing = false;
	bool isColoring = false;
	// -- Images --- //
	sf::Image brush;
	// --- Textures --- //
	std::vector<sf::CircleShape> paintWhiteBoardElements;
	sf::Texture logoDVD;
	sf::Texture smallAppIcon;
	sf::Texture closeWindowIcon;
	sf::Texture minimizeWindowIcon;
	sf::Texture paintTopBarPaletteEraserTexture;
	sf::Texture paintTopBarPaletteClearAllTexture;
	sf::Texture paintTopBarPaletteDrawBrushTexture;
	sf::Texture paintTopBarPaletteDrawPenTexture;
	sf::Texture paintTopBarPaletteThicknessPlusTexture;
	sf::Texture paintTopBarPaletteThicknessMinusTexture;
	// --- Sprites --- //
	sf::Sprite smallAppIconSpr;
	sf::Sprite closeWindowIconSpr;
	sf::Sprite minimizeWindowIconSpr;
	sf::Sprite sprLogoDVD;
	sf::Sprite paintTopBarPaletteClearSectionEraser;
	sf::Sprite paintTopBarPaletteClearSectionClearAll;
	sf::Sprite paintTopBarPaletteDrawSectionBrush;
	sf::Sprite paintTopBarPaletteDrawSectionPen;
	sf::Sprite paintTopBarPaletteThicknessPlus;
	sf::Sprite paintTopBarPaletteThicknessMinus;
	// --- Fonts --- //
	sf::Font Impact, Arial, Comic, GoodTiming;
	// --- Texts "All modes" --- //
	std::string mode = "default";
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
	// --- Shapes "paint" --- //
	sf::RectangleShape paintWhiteBoard;
	sf::RectangleShape paintTopBarPalette;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorBlack;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorWhite;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorRed;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorGreen;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorBlue;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorPurple;
	sf::RectangleShape paintTopBarPaletteColorsSectionColorPink;
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
	sf::Music TBKTileBroken; // TODO : Add it

private:
	void initFonts();
	void initTextures();
	void initTexts();
	void pollEvents();
	void update();
	void render();
};

 #endif // !GAME_H