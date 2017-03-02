#include <SFML\Graphics.hpp>
#include "Car.h"
#include "RoadMarkings.h"
#include "Road.h"
#include "Observer.h"
#include "Menu.h"
#include "Game.h"

void main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Test Car");
	window.setFramerateLimit(60);
	
	Car * car	= new Car();
	Road * road = new Road();
	RoadMarkings *roadMarks =	new RoadMarkings(3);
	Observer * observer =		new Observer(car, roadMarks);
	Menu * menu = new Menu(car, roadMarks, observer);
	Game * game = new Game(car, roadMarks, observer, road);
	
	bool isMenu = true;


	while (window.isOpen())
	{
		sf::Event event;

		if (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		menu->show(&window, isMenu);
		game->play(&window, isMenu);
		
		window.display();
	}
	delete game;
	delete menu;
	delete observer;
	delete roadMarks;
	delete road;
	delete car;
}