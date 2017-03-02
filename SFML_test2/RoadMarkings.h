#pragma once
#include "MyLine.h"
#include <SFML\Graphics.hpp>
class RoadMarkings
{
	MyLine * Array;
	float x;
	int N;
public:
	RoadMarkings(int N);
	
	void setX(float x);
	float getX();
	void move(double vertSpeed);
	float getXofMarksByY(float Y);
	void draw(sf::RenderWindow &window);
	bool isCross(float pointOneX, float pointOneY, float pointTwoX, float pointTwoY);
	~RoadMarkings();
};

