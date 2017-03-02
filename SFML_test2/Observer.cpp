#include "Observer.h"

Observer::Observer(Car *car, RoadMarkings *roadMarks)
{
	this->roadMarks = roadMarks;
	this->car = car;
	x = car->getX();
	y = car->getY();
	isLeftSide = checkSide();
	isOppositeDirectionLeft = false;
	isOppositeDirectionRight = false;
	vectorOfSpeed[0] = car->getHorizontalSpeed(); 
	vectorOfSpeed[1] = car->getVerticalSpeed();
	angle = car->getAngle();
	reverseMove = true;
	showDetails = true;
	allowSlowingMove = false;

	font = new sf::Font();
	font->loadFromFile("media/calibri.ttf");
	text = new sf::Text("", *font, 20);
	text->setPosition(50, 35);
	textOppositeDirection = new sf::Text("",*font,20);
	textOppositeDirection->setPosition(50, 220);
	textCross = new sf::Text("", *font, 20);
	textCross->setPosition(50, 250);
	text->setStyle(sf::Text::Bold);
}

void Observer::check()
{
	nextX = car->getX();
	nextY = car->getY();
	nextVectorSpeed[0] = car->getHorizontalSpeed();
	nextVectorSpeed[1] = car->getVerticalSpeed();
	if (checkSide() != isLeftSide)
	{
		isLeftSide = checkSide();
		isOppositeDirectionLeft = false;
		isOppositeDirectionRight = false;
	}

	if (reverseMove)
	{
		angle = car->getDirection();
	}
	else
	{
		if (vectorOfSpeed[0] != 0)
			angle = atan(vectorOfSpeed[1] / vectorOfSpeed[0]) * 180 / 3.14;
	}

	if (allowSlowingMove) //если разрешено движение с замедлением
	{
		float deltaSpeed = nextVectorSpeed[1] - vectorOfSpeed[1];
		if (reverseMove)	//если движение задом включено
		{
			if (isLeftSide)
			{
				if ((nextVectorSpeed[1] < 0) && deltaSpeed < 0.01)
				{
					if ((angle < 1.57) || (angle > 4.71))
						isOppositeDirectionLeft = true;
					else
						isOppositeDirectionLeft = false;
				}
				else
					isOppositeDirectionLeft = false;
					
			}
			else
			{
				if ((nextVectorSpeed[1] > 0) && (deltaSpeed > -0.01))
				{
					if ((angle > 1.57) && (angle < 4.71))
						isOppositeDirectionRight = true;
					else
						isOppositeDirectionRight = false;
				}
				else
				{
					isOppositeDirectionRight = false;
				}
			}
		}
		else
		{
			if (isLeftSide)//если двигаемся по левой части
			{
				if ((nextVectorSpeed[1] < 0) && (deltaSpeed<0.01))
					isOppositeDirectionLeft = true;
				else
					isOppositeDirectionLeft = false;
			}
			else
			{
				if ((nextVectorSpeed[1] > 0) && (deltaSpeed>-0.01))
					isOppositeDirectionRight = true;
				else
					isOppositeDirectionRight = false;
			}
		}
	}
	else
	{
		if (reverseMove)	//если движение задом включено
		{
			if (isLeftSide)
			{
				if (nextVectorSpeed[1] < 0)
				{
					if ((angle < 1.57) || (angle > 4.71))
						isOppositeDirectionLeft = true;
					else
						isOppositeDirectionLeft = false;
				}
				else
					isOppositeDirectionLeft = false;
			}
			else
			{
				if (nextVectorSpeed[1] > 0)
				{
					if ((angle > 1.57) && (angle < 4.71))
						isOppositeDirectionRight = true;
					else
						isOppositeDirectionRight = false;
				}
				else
					isOppositeDirectionRight = false;
			}
		}
		else
		{
			if (isLeftSide)//если двигаемся по левой части
			{
				if (nextVectorSpeed[1] < 0)
					isOppositeDirectionLeft = true;
				else
					isOppositeDirectionLeft = false;
			}
			else
			{
				if (nextVectorSpeed[1] > 0)
					isOppositeDirectionRight = true;//std::cout << "8Move ooposite direction(right side of road)" << std::endl;
				else
					isOppositeDirectionRight = false;
			}
		}
	}

	if (roadMarks->isCross(x, y, nextX, nextY))
	{
		crossString += "Cross the line!\n";
		clock.restart();
		if (crossString.length() > 50)
		{
			crossString = "Cross the line!\n";
			clock.restart();
		}
	}
	if (clock.getElapsedTime().asSeconds() > 2)
	{
		clock.restart();
		crossString = "";
	}

	x = nextX;
	y = nextY;
	vectorOfSpeed[0] = nextVectorSpeed[0];
	vectorOfSpeed[1] = nextVectorSpeed[1];
}

void Observer::draw(sf::RenderWindow & window)
{
	if (showDetails)
	{
		std::string tmpString = "VerticalSpeed = ";
		char buffer[10];
		sprintf_s(buffer, 10, "%.2f", car->getVerticalSpeed());
		tmpString.append(buffer);
		tmpString += "\nangle =";
		sprintf_s(buffer, 10, "%.2f", angle);
		tmpString.append(buffer);
		tmpString += "\nVectorOfSpeed = ";
		sprintf_s(buffer, 10, "%.2f ", vectorOfSpeed[0]);
		tmpString.append(buffer);
		sprintf_s(buffer, 10, "%.2f", vectorOfSpeed[1]);
		tmpString.append(buffer);
		if (isLeftSide) tmpString += "\nLeft Side";
		else tmpString += "\nRightSide";
		tmpString += "\nCoordOfCar: ";
		sprintf_s(buffer, 10, "%.2f,", car->getX());
		tmpString.append(buffer);
		sprintf_s(buffer, 10, " %.2f", car->getY());
		tmpString.append(buffer);
		text->setString(tmpString);

		window.draw(*text);
	}

	if (isOppositeDirectionLeft)
		textOppositeDirection->setString("Move oposite direction(LEFT side of road)");
	else if(isOppositeDirectionRight)
		textOppositeDirection->setString("Move oposite direction(RIGHT side of road)");
	else
		textOppositeDirection->setString("");
	
	textCross->setString(crossString);
	
	window.draw(*textOppositeDirection);
	window.draw(*textCross);
}

void Observer::setShowDetails(bool showDetails)
{
	this->showDetails = showDetails;
}

void Observer::setReverseMove(bool reverseMove)
{
	this->reverseMove = reverseMove;
}

void Observer::setAllowSlowingMove(bool allowSlowingMove)
{
	this->allowSlowingMove = allowSlowingMove;
}

Observer::~Observer()
{
	delete font;
	delete text;
	delete textOppositeDirection;
	delete textCross;

}

bool Observer::checkSide()
{
	if (x < roadMarks->getX())
		return true;
	else
		return false;
}
