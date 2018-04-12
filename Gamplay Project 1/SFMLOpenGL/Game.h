#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Player.h"
#include "NPC.h"
#include "Goal.h"

#include <Debug.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

using namespace std;
using namespace sf;
using namespace glm;

class Game
{
public:
	Game();
	Game(sf::ContextSettings settings);
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize(); 
	void update();
	void render();
	void unload();

	//player class
	Player player;
	//npc class 
	NPC npc;
	//goal class
	Goal goal;
	//font for score
	sf::Font font;
};

#endif