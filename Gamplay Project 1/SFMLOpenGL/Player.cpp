#include "Player.h"


Player::Player()
{
}

Player::~Player()
{
}

//initialise the position of the player cube
void Player::initialize(static GLfloat vertices[])
{
	for (int i = 0, index = 0; i < 72, index < 24; i = i + 3, index++)
	{
		currentPosition[index] = Vector3D{ vertices[i], vertices[i + 1], vertices[i + 2] };
	}
	for (int i = 0, index = 0; i < 72, index < 24; i = i + 3, index++)
	{
		vertices[i] = currentPosition[index].X();
		vertices[i + 1] = currentPosition[index].Y();
		vertices[i + 2] = currentPosition[index].Z();
	}
	for (size_t i = 0; i < 24; i++)
	{
		originalPosition[i] = currentPosition[i];
	}
}

//update the position of the player cube when moving
void Player::update(static GLfloat vertices[])
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (size_t i = 0; i < 24; i++)
		{
			currentPosition[i] = (Matrix3::translation(activeTranslation) * currentPosition[i]) - Vector3D(0.01, 0, 0);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (size_t i = 0; i < 24; i++)
		{
			currentPosition[i] = (Matrix3::translation(activeTranslation) * currentPosition[i]) + Vector3D(0.01, 0, 0);
		}
	}

	for (int i = 0, index = 0; i < 72, index < 24; i = i + 3, index++)
	{
		vertices[i] = currentPosition[index].X();
		vertices[i + 1] = currentPosition[index].Y();
		vertices[i + 2] = currentPosition[index].Z();
	}
}

//resets the position of the player cube to its original position
void Player::reset()
{
	for (size_t i = 0; i < 24; i++)
	{
		currentPosition[i] = originalPosition[i];
	}
}
