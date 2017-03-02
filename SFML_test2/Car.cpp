#include "Car.h"

Car::Car()
{
	texture.loadFromFile("media/Aston-Martin50x100x8bit.png");
	sprite.setTexture(texture);
	x = 450; 
	y = 420;
	angle = 0;
	speed = 0;
	radius = 100;
	sprite.setOrigin(25, 50);
	sprite.setPosition(x, y);
}

void Car::Move()
{
	bool Up = false, Down = false, Left = false, Right = false;
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) Up = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) Down = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) Left = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Right = true;

	if (Up&&speed < maxSpeed)
	{
		speed += 0.5;
	}
	if (Down&&speed > -5)
	{
		speed -= 1;
	}
	if (!Up && !Down)
	{
		if (speed - 0.2 > 0) speed -= 0.2;
		else if (speed + 0.2 < 0) speed += 0.2;
		else
			speed = 0;
	}
	
	if (Left&&speed!=0)
	{
		angle -= 1/(radius/2) * speed;
		
	}
	if (Right&&speed != 0)
	{
		angle += 1/(radius/2) * speed;
	}

	x = x + sin(angle) * speed;
	y = y - cos(angle) * speed;
		
	sprite.setRotation(angle*180/3.14);
	sprite.setPosition(x, y);
}

sf::Sprite Car::getSprite()
{
	return sprite;
}

float Car::getVerticalSpeed()
{
	return -cos(angle) * speed;
}

float Car::getHorizontalSpeed()
{
	return -sin(angle)*speed;
}

void Car::setSpeed(float speed)
{
	this->speed = speed;
}

float Car::getX()
{
	return x;
}

void Car::setX(double setX)
{
	x = setX;
}

float Car::getY() 
{
	return y;
}

void Car::setY(double setY)
{
	y = setY;
}

void Car::setPosition(double setX, double setY)
{
	x = setX;
	y = setY;
}

float Car::getAngle()
{
	return angle;
}

void Car::setMaxSpeed(float maxSpeed)
{
	this->maxSpeed = maxSpeed;
}

void Car::setRadius(float radius)
{
	this->radius = radius;
}

float Car::getDirection()
{
	float tmp = this->getAngle();
	tmp = fmodf(abs(tmp), (6.28318));
	return tmp;
}

Car::~Car()
{
}
