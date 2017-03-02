#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

class MyLine
{
	sf::VertexArray line;
	int N;
public:
	MyLine();
	MyLine(float x1, float y1, float x2, float y2);
	void moveUp(float vertSpeed);
	void moveDown(float vertSpeed);
	sf::VertexArray &getVertexArray();
	float getMaxY();
	float getMinY();
	~MyLine();
};

