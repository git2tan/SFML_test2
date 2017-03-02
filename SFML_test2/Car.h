#pragma once
#include <SFML\Graphics.hpp>
//#include <iostream>
class Car
{
	sf::Texture texture;
	sf::Sprite sprite;
	float x, y;
	float maxSpeed;
	float speed;
	float angle;
	float radius;
public:
	Car();
	void Move();
	sf::Sprite getSprite();
	float getVerticalSpeed();
	float getHorizontalSpeed();
	void setSpeed(float speed);
	float getX();
	void setX(double setX);
	float getY();
	void setY(double setY);
	void setPosition(double setX, double setY);
	float getAngle();
	void setMaxSpeed(float maxSpeed);
	void setRadius(float radius);
	float getDirection();
	~Car();
};

