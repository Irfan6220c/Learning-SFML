#include <thread>
#include <chrono>
#include "Header.h"
#include <iostream>
//GameClass Constructor
GameClass::GameClass()
{
	this->m_GameRender();
}

//GameClass Destructor
GameClass::~GameClass()
{
	if (this->m_Window)
	{
		delete[] this->m_Window;
	}
}

void GameClass::m_WindowInitialization()
{
	this->m_VidMode.height = 1000;
	this->m_VidMode.width = 1000;
	this->m_Name = "Blocks Game";
	this->m_Window = new sf::RenderWindow(this->m_VidMode,this->m_Name);
	this->m_Window->setFramerateLimit(60);
}

void GameClass::m_VaariableInit()
{
	//m_Window to Null pointer//
	this->m_Window = nullptr;
	m_initime = 0;
	m_finalTime = 20;
	this->m_Duration = 30;
	this->m_Score = 0;

}

void GameClass::m_GameInit()
{
	this->m_VaariableInit();
	this->m_WindowInitialization();
	this->m_RectInit();
}

void GameClass::m_GameRender()
{
	this->m_GameInit();
	this->buffer.loadFromFile("Sound.wav");
	this->sound.setBuffer(this->buffer);
	this->sound.play();
	this->sound.setLoop(true);

	while(m_initime <=m_finalTime)
	{

		this->m_Pollevent();
		this->m_UpdateRect( );
		this->m_Window->clear();
		this->m_Draw();

		this->m_Window->display();
		std::this_thread::sleep_for(std::chrono::nanoseconds(this->m_Duration));
		m_initime += 0.5;
		if (this->m_Duration>1)
		{
			//std::cout << m_Duration;
			this->m_Duration -= 1;
		}
		//std::cout << this->m_Score << std::endl;

	}
	
}

void GameClass::m_RectInit()
{

	for (int i = 0; i < m_RectVec.size(); ++i)
	{
		this->m_RectVec[i].setSize(sf::Vector2f(150, 150));
		this->m_RectVec[i].setFillColor(sf::Color::Blue);
		this->m_RectVec[i].setPosition(10+this->m_RecnitPos, 10);
		this->m_RectVec[i].setScale(sf::Vector2f(0.5, 0.5));
		this->m_RecnitPos += 200;
	}
}

void GameClass::m_UpdateRect()

{

			for (int i = 0; i < m_RectVec.size(); ++i)
			{
				if (m_RectVec[i].getPosition().y>1000)
				{
					m_RectVec[i].setPosition(m_RectVec[i].getPosition().x, 10);

				}
				this->m_RectVec[i].move(sf::Vector2f(0, 10));
			}

}

void GameClass::m_Draw()
{
	for (auto i : m_RectVec)
	{
		this->m_Window->draw(i);
	}
}

void GameClass::m_Pollevent()
{

		while (this->m_Window->pollEvent(this->m_Event))
		{
			if (this->m_Event.type == sf::Event::Closed)
			{
				this->m_Window->close();

			}
			if (this->m_Event.type == sf::Event::MouseMoved)
			{

				//std::cout << sf::Mouse::getPosition().x << " "
					//<< sf::Mouse::getPosition().y << " ";

			}
			if (this->m_Event.type == sf::Event::MouseButtonPressed)
			{
				if (this->m_Event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < m_RectVec.size(); ++i)
					{
						if (this->m_RectVec[i].getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*this->m_Window))))
						{
							this->m_RectVec[i].setFillColor(sf::Color::Green);
							this->m_RectVec[i].setPosition(m_RectVec[i].getPosition().x, -200);
							this->m_Score += 10;
						}
					}

				}
			}
		}
}

bool GameClass::m_window_Status()
{
	return this->m_Window->isOpen();
}



