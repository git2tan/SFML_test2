#include "MyLine.h"
#include <SFML\Graphics.hpp>


MyLine::MyLine()
{
	line = sf::VertexArray(sf::Lines,2);
	line[0].position = sf::Vector2f(100, 200);
	line[1].position = sf::Vector2f(50, 50);
}

MyLine::MyLine(float x1, float y1, float x2, float y2)
{
	this->line = sf::VertexArray(sf::Lines, 2);
	line[0].position = sf::Vector2f(x1, y1);
	line[1].position = sf::Vector2f(x2, y2);
}

void MyLine::moveUp(float vertSpeed)
{
	line[0].position.y -= vertSpeed;
	line[1].position.y -= vertSpeed;
}

void MyLine::moveDown(float vertSpeed)
{
	line[0].position.y -= vertSpeed;
	line[1].position.y -= vertSpeed;
}

sf::VertexArray &MyLine::getVertexArray()
{
	return line;
}

float MyLine::getMaxY()
{
	return line[0].position.y>line[1].position.y? line[0].position.y: line[1].position.y;
}

float MyLine::getMinY()
{
	return line[0].position.y<line[1].position.y ? line[0].position.y : line[1].position.y;
}

MyLine::~MyLine()
{
	
}
