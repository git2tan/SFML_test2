#pragma once
#include "Car.h"
#include "RoadMarkings.h"
#include "Observer.h"
#include <Windows.h>

class Menu
{
	Car * car;
	RoadMarkings *roadMarks;
	Observer * observer;
	sf::Texture textureOn;
	sf::Texture textureOff;
	sf::Texture textureUp;
	sf::Texture textureDown;
	sf::Font *font;
	bool showDetails;
	bool reverseMove;
	bool allowSlowingMove;
	int maxSpeed;
	int radius;
	sf::Sprite chBox1;
	sf::Text *text;
	sf::Sprite chBox2;
	sf::Text * textReverse;
	sf::Text *textMaxSpeed;	//сделать чтобы не стало отрицательной или слишком большой
	sf::Sprite buttonUp1;
	sf::Sprite buttonDown1;
	sf::Text *textExit;

	//ѕункт страт
	sf::Text *textStart;
	
	//ѕункт - радиус (текст+2кнопки)
	sf::Text *textRadius;
	sf::Sprite buttonUp2;
	sf::Sprite buttonDown2;

	//ѕунтк - разрешить замедл€ющеес€ движение в обратном направлении
	sf::Text *textAllowSlowingMove;
	sf::Sprite chBox3;

public:
	Menu(Car* car, RoadMarkings * roadMarks, Observer * observer);
	void show(sf::RenderWindow *window, bool &isMenu);
	~Menu();
};

