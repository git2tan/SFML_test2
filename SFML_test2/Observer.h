#pragma once
#include "Car.h"
#include <SFML\Graphics.hpp>
#include <string.h>
#include "RoadMarkings.h"

class Observer
{
	RoadMarkings * roadMarks;
	Car *car;
	float x, y,nextX,nextY;
	float angle;
	float vectorOfSpeed [2];
	float nextVectorSpeed[2];
	bool isOppositeDirectionLeft;
	bool isOppositeDirectionRight;
	bool isLeftSide;
	sf::Font *font;
	sf::Text *text;
	sf::Text * textOppositeDirection;
	sf::Text * textCross;
	bool showDetails;
	bool reverseMove;
	bool allowSlowingMove;
	std::string crossString="";
	sf::Clock clock;

public:
	Observer(Car *car, RoadMarkings* roadMarks);
	void check();
	void draw(sf::RenderWindow &window);
	void setShowDetails(bool showDetails);
	void setReverseMove(bool reverseMove);
	void setAllowSlowingMove(bool allowSlowingMove);
	~Observer();
private:
	bool checkSide();
};

