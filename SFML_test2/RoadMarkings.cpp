#include "RoadMarkings.h"


RoadMarkings::RoadMarkings(int N)
{
	x = 400;
	this->N = N;
	MyLine *tmp = new MyLine[N];
	for (int i = 0; i < N; i++)
	{
		tmp[i] = MyLine(x,0+600*i,x,-400+600*i);
	}
	Array = tmp;
}



void RoadMarkings::setX(float x)
{
	this->x = x;
	for (int i = 0; i < N; i++)
	{
		Array[i].getVertexArray()[0].position.x = x;
		Array[i].getVertexArray()[1].position.x = x;
	}
}

float RoadMarkings::getX()
{
	return x;
}

void RoadMarkings::move(double vertSpeed)
{
	for (int i = 0; i < N; i++)
	{
		Array[i].moveUp(vertSpeed);
		
		if (Array[i].getMaxY() < -00)
		{
			Array[i].moveDown(-1400);
		}
		if (Array[i].getMinY() > 800)
		{
			Array[i].moveUp(1400);
		}
	}
}

float RoadMarkings::getXofMarksByY(float Y)
{
	
}

void RoadMarkings::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < N; i++)
	{
		window.draw(Array[i].getVertexArray());
	}
}

bool RoadMarkings::isCross(float pointOneX, float pointOneY, float pointTwoX, float pointTwoY)
{
	//находим ординату точки на переданном отрезке с абсциссой x
	if ((pointOneX<x&&pointTwoX>x) || (pointOneX > x&&pointTwoX < x))
	{
		float y = pointOneY + (((pointTwoY - pointOneY) / (pointTwoX - pointTwoY))*(x - pointOneX));
		for (int i = 0; i < N; i++)
		{
			if ((y<Array[i].getVertexArray()[0].position.y&&y>Array[i].getVertexArray()[1].position.y))
				return true;
			else if (y<Array[i].getVertexArray()[1].position.y&&y>Array[i].getVertexArray()[0].position.y)
				return true;
		}
	}
	return false;
}

RoadMarkings::~RoadMarkings()
{
	delete[] Array;
}
