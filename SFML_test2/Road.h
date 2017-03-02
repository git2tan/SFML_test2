#pragma once
#include <SFML\Graphics.hpp>

class Road
{
	sf::Texture texture;
	sf::Sprite sprite;
	float x, y;
public:
	Road();
	void move(float speed);
	sf::Sprite getSprite();
	~Road();
};

