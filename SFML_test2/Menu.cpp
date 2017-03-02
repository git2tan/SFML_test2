#include "Menu.h"



Menu::Menu(Car* car, RoadMarkings * roadMarks, Observer * observer)
{
	//������������� ����������
	this->car = car;
	this->roadMarks = roadMarks;
	this->observer = observer;
	showDetails = true;
	reverseMove = true;
	allowSlowingMove = false;
	maxSpeed = 10;
	radius = 300;

	//�������� ������ � ������ ��� ����
	textureOff.loadFromFile("media/flagOffW1.png");
	textureOn.loadFromFile("media/flagOnW1.png");
	textureUp.loadFromFile("media/buttonUp.png");
	textureDown.loadFromFile("media/buttonDown.png");
	font = new sf::Font();
	font->loadFromFile("media/calibri.ttf");
	
	//������� ������
	chBox1.setPosition(450, 50);
	text = new sf::Text(L"���������� ������", *font, 16);
	text->setPosition(35, 50);
	
	//������� ������ ���
	chBox2.setPosition(450, 80);
	textReverse = new sf::Text(L"��������� ������ ��� ��������� ��������", *font, 16);
	textReverse->setPosition(35, 80);
	
	//��������� ��������
	textMaxSpeed = new sf::Text("", *font, 16);
	buttonUp1.setTexture(textureUp);
	buttonUp1.setPosition(450, 110);
	buttonDown1.setTexture(textureDown);
	buttonDown1.setPosition(450, 130);
	textMaxSpeed->setPosition(35, 110);
	
	//��������� ������� ���������
	textRadius = new sf::Text("", *font, 16);
	textRadius->setPosition(35, 160);
	buttonUp2.setTexture(textureUp);
	buttonUp2.setPosition(450, 160);
	buttonDown2.setTexture(textureDown);
	buttonDown2.setPosition(450, 180);

	//������� ������������� ��������
	chBox3.setPosition(450, 210);
	textAllowSlowingMove = new sf::Text(L"��������� ������������� �������� �� ���������", *font, 16);
	textAllowSlowingMove->setPosition(35, 210);

	//�������/������ �����
	textStart = new sf::Text("START", *font, 30);
	textStart->setPosition(50, 450);

	//�������/������ �����
	textExit = new sf::Text("EXIT", *font, 30);
	textExit->setPosition(450, 450);
}

void Menu::show(sf::RenderWindow * window, bool &isMenu)
{
	if (isMenu)
	{
		//bool isExit = false;
		
		//////�������� �������� ��� ���������
		if (showDetails) chBox1.setTexture(textureOn);
		else chBox1.setTexture(textureOff);

		if (reverseMove) chBox2.setTexture(textureOn);
		else chBox2.setTexture(textureOff);

		if (allowSlowingMove) chBox3.setTexture(textureOn);
		else chBox3.setTexture(textureOff);
		
		char buf[10];
		//��������� ������ �� ���������
		std::string tmpMaxSpeed = "~MaxSpeed:            ";
		sprintf_s(buf, 10, "%d", maxSpeed);
		tmpMaxSpeed.append(buf);
		textMaxSpeed->setString(tmpMaxSpeed);
		
		//��������� ������ � ��������
		std::string tmpRadius = "~Turning radius:      ";
		sprintf_s(buf, 10, "%d", radius);
		tmpRadius.append(buf);
		textRadius->setString(tmpRadius);
		
		//
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);

		//������� - ���������� ��� ����������
		if (chBox1.getGlobalBounds().contains(mousePos.x, mousePos.y)||(*text).getGlobalBounds().contains(mousePos.x,mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				showDetails = !showDetails;
				Sleep(200);		//������� ��� ��� ���, �� ��-������� ���� �� ����� ��� ����� ������ �������� ������������� ���������� �����
			}
		}

		//������� - ��������� �������� ����� �� ��������
		if (chBox2.getGlobalBounds().contains(mousePos.x, mousePos.y) || (*textReverse).getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				reverseMove = !reverseMove;
				Sleep(200);		//������� ��� ��� ���, �� ��-������� ���� �� ����� ��� ����� ������ �������� ������������� ���������� �����
			}
		}

		//��������� ������������ ��������
		if (buttonUp1.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				maxSpeed++; //������� ����� �� ����� ������������� ��� ������� �������
				Sleep(200);
			}
		}
		if (buttonDown1.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				maxSpeed--; //������� ����� �� ����� ������������� ��� ������� �������
				Sleep(200);
			}
		}

		//��������� ������� ���������
		if (buttonUp2.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				//������� ����� �� ����� ������������� ��� ������� �������
				radius = radius % 400+25;
				Sleep(200);
			}
		}
		if (buttonDown2.getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
					radius = (400 + radius)%425;
					if (radius == 0)
						radius = 400;
				Sleep(200);
			}
		}

		//������� - ��������� �������� �� �������� � �����������
		if (chBox3.getGlobalBounds().contains(mousePos.x, mousePos.y) || (*text).getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && (sf::Mouse::ButtonCount > 3))
			{
				allowSlowingMove = !allowSlowingMove;
				Sleep(200);		//������� ��� ��� ���, �� ��-������� ���� �� ����� ��� ����� ������ �������� ������������� ���������� �����
			}
		}
		
		//���� ������ ������ "�����"
		if (textStart->getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				isMenu = false;
				car->setMaxSpeed(maxSpeed);
				car->setRadius(radius);
				observer->setReverseMove(reverseMove);
				observer->setShowDetails(showDetails);
				observer->setAllowSlowingMove(allowSlowingMove);
				Sleep(100);
			}
		}
		
		//���� ������ ������ "�����"
		if (textExit->getGlobalBounds().contains(mousePos.x, mousePos.y))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
				window->close();
		}
		//������ ESC
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			isMenu = false;
			car->setMaxSpeed(maxSpeed);
			car->setRadius(radius);
			observer->setReverseMove(reverseMove);
			observer->setShowDetails(showDetails);
			observer->setAllowSlowingMove(allowSlowingMove);
			Sleep(100);
		}
		
		//������������ ��� �������
		window->draw(*text);
		window->draw(*textReverse);
		window->draw(chBox1);
		window->draw(chBox2);
		window->draw(*textMaxSpeed);
		window->draw(buttonUp1);
		window->draw(buttonDown1);
		window->draw(*textStart);
		window->draw(*textExit);
		window->draw(*textRadius);
		window->draw(buttonUp2);
		window->draw(buttonDown2);
		window->draw(chBox3);
		window->draw(*textAllowSlowingMove);
	}
}


Menu::~Menu()
{
	delete font;
	delete text;
	delete textReverse;
	delete textMaxSpeed;
	delete textExit;
	delete textStart;
	delete textRadius;
	delete textAllowSlowingMove;
	//�� ������ ��������� ������
}
