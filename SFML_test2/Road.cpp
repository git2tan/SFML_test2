#include "Road.h"

Road::Road()
{
	texture.loadFromFile("media/road1.png");
	sprite.setTexture(texture);
	sprite.setOrigin(400, 500);
	sprite.setPosition(400, 400);
}

void Road::move(float speed)
{
	sprite.setPosition(400, sprite.getPosition().y - speed);
	if (sprite.getPosition().y < 300)
		sprite.setPosition(400, 500);
	if(sprite.getPosition().y>500)
		sprite.setPosition(400, 300);
}

sf::Sprite Road::getSprite()
{
	return sprite;
}

Road::~Road()
{
}
