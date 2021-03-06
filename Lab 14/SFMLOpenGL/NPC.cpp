#include "NPC.h"

NPC::NPC()
{
}

NPC::~NPC()
{
}

void NPC::initialize(GLfloat vertices[])
{
	for (int i = 72, index = 0; i < 216, index < 72; i = i + 3, index++)
	{
		currentPosition[index] = Vector3D{ vertices[i], vertices[i + 1], vertices[i + 2] };
	}
	for (int i = 72, index = 0; i < 216, index < 72; i = i + 3, index++)
	{
		vertices[i] = currentPosition[index].X();
		vertices[i + 1] = currentPosition[index].Y();
		vertices[i + 2] = currentPosition[index].Z();
	}
}

void NPC::update(GLfloat vertices[])
{

	xRotation = Matrix3::rotationX(0.00174533);//angle set to 2 degrees
	for (size_t i = 0; i < 24; i++)
	{
		currentPosition[i] = (xRotation * currentPosition[i]);
	}

	yRotation = Matrix3::rotationY(0.00174533);//angle set to 2 degrees
	for (size_t i = 24; i < 48; i++)
	{
		currentPosition[i] = yRotation * currentPosition[i];
	}

	zRotation = Matrix3::rotationZ(0.00174533);//angle set to 2 degrees
	for (size_t i = 48; i < 72; i++)
	{
		currentPosition[i] = zRotation * currentPosition[i];
	}

	for (int i = 72, index = 0; i < 216, index < 72; i = i + 3, index++)
	{
		vertices[i] = currentPosition[index].X();
		vertices[i + 1] = currentPosition[index].Y();
		vertices[i + 2] = currentPosition[index].Z();
	}
}
