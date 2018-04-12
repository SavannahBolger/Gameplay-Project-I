#pragma once
#include <iostream>
#include <GL/glew.h>
#include <GL/wglew.h>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include "Vector3D.h"
#include "Matrix3.h"

class NPC
{
public:
	NPC();
	~NPC();

	Vector3D currentPosition[72];
	Vector3D originalPosition[72];
	Matrix3 xRotation;//x axis rotation
	Matrix3 yRotation;//y axis rotation
	Matrix3 zRotation;//z axis rotation
	Vector3D activeTranslation{ 0,0,0 };

	void initialize(static GLfloat vertices[]);//initialise the npc cube position
	void update(static GLfloat vertices[]);//update npc cube  rotation movement
};
