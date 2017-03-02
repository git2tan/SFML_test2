#include "Game.h"



Game::Game(Car* car, RoadMarkings * roadMarks, Observer * observer, Road *road)
{
	this->car = car;
	this->roadMarks = roadMarks;
	this->observer = observer;
	this->road = road;
}

void Game::play(sf::RenderWindow *window, bool & isMenu)
{
	if (!isMenu)
	{
		car->Move();
		observer->check();
		double speed = car->getVerticalSpeed();
		if (car->getY()<150)
		{
			road->move(speed);
			roadMarks->move(speed);
			car->setY(149);
		}
		if (car->getY() > 380)
		{
			road->move(speed);
			roadMarks->move(speed);
			car->setY(379);
		}
		if (car->getX() < 50)
		{
			car->setX(50);
			car->setSpeed(0);
		}
		if (car->getX() > 750)
		{
			car->setX(750);
			car->setSpeed(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			isMenu = true;
			Sleep(200);
		}
		roadMarks->draw(*window);
		(*window).draw(road->getSprite());
		(*window).draw(car->getSprite());
		observer->draw((*window));
	}
}


Game::~Game()
{
}
