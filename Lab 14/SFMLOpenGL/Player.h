#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3D.h"
#include "Matrix3.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player();
	~Player();

	Vector3D currentPosition[24];
	Vector3D activeTranslation{ 0,0,0 };

	void initialize(static GLfloat vertices[]);
	void update(static GLfloat vertices[]);

};