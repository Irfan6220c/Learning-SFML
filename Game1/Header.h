#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>

class GameClass
{
public:
	GameClass();

	~GameClass();

	void m_WindowInitialization();
	void m_VaariableInit();
	void m_Pollevent();
	bool m_window_Status();
	void m_GameInit();
	void m_GameRender();
	void m_RectInit();
	void m_UpdateRect();
	void m_Draw();




private:
	sf::RenderWindow* m_Window;
	sf::VideoMode     m_VidMode;
	sf::Event         m_Event;
	std::vector<sf::RectangleShape>  m_RectVec{5};
	float             m_RecnitPos{};
	sf::VertexArray   Rect;
	std::string       m_Name;
	int               m_initime{};
	int               m_finalTime{};
	int               m_Duration{};
	float             m_Score{};
	sf::SoundBuffer   buffer;
	sf::Sound         sound;
};