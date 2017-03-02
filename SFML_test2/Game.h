#pragma once
#include "Car.h"
#include "RoadMarkings.h"
#include "Observer.h"
#include "Road.h"
#include <Windows.h>

class Game
{
	Car * car;
	RoadMarkings *roadMarks;
	Observer * observer;
	Road * road;
public:
	Game(Car* car, RoadMarkings * roadMarks, Observer * observer, Road * road);
	void play(sf::RenderWindow *window, bool &isMenu);
	~Game();
};

