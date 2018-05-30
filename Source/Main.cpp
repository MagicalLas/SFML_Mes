//STD
#include<iostream>
//Other
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include "../Library/Imgui/imgui.h"
#include "../Library/Imgui/imgui-SFML.h"
//Wonho
#include"../Include/Resource.h"
#include"../Include/Useful.h"

int main(){
	
	
	std::cout <<"Biuld Success" << std::endl;
	std::cout << "Program Start!" << std::endl;

	//WON API
	Wonho_pp::Resource res("../../Resource");
	Wonho_pp::String_Helper StringHelper;
	Wonho_pp::Screen_Move ScreenHelper;


	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");
	window.setFramerateLimit(60);

	ImGui::SFML::Init(window);
	sf::Text text;
	sf::Font font;
	
	if (!font.loadFromFile(res.getPath("font.ttf")))
	{
		std::cout << "Font can't find\n";
	}
	text.setFont(font);

	text.setString(L"Test Text");
	text.setCharacterSize(24);
	ScreenHelper.setMiddle(text);
	text.setPosition(400, 400);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
			}
		}

		window.clear();

		window.draw(text);
		window.display();
	}

	std::cout << "Program End - Las\n";
	return 0;
}