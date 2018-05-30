//STD
#include<iostream>
//Other
#include<SFML/Graphics.hpp>
//Wonho
#include"../Include/Resource.h"
#include"../Include/Useful.h"

int main() {
	std::cout << "Biuld Success" << std::endl;
	std::cout << "Program Start!" << std::endl;

	//WON API
	Wonho_pp::Resource res("../../Resource");
	Wonho_pp::String_Helper StringHelper;
	Wonho_pp::Screen_Move ScreenHelper;

	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");

	sf::Text text;
	sf::Font font;

	if (!font.loadFromFile(res.getPath("font.ttf")))
	{
		std::cout << "Font can't find\n";
	}
	text.setFont(font);

	text.setString(L"원호는 바보다");
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
				text.setString(L"아마도 아닐수도 있지만 상관없다.");
				ScreenHelper.setMiddle(text);
			}
		}

		window.clear();

		window.draw(text);
		window.display();
	}

	std::cout << "Program End - Las\n";
	return 0;
}