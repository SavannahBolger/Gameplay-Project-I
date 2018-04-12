#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3D.h"
#include "Matrix3.h"

class Goal
{
public:
	Goal();
	~Goal();

	Vector3D currentPosition[24];
	Vector3D activeTranslation{ 0,0,0 };
	Vector3D originalPosition[24];
	int score = 0; //game score
	bool active = false; //is the goal cube moving
	void initialize(static GLfloat vertices[]); //initialise the goal cube position
	void update(static GLfloat vertices[]); //update goal cube movement
	void reset(); //reset the goal cube position to original

};