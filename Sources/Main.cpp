//STD
#include<iostream>
//Other
#include<SFML/Graphics.hpp>
#include"../../../Libraries/imgui/imgui.h"
#include"../../../Libraries/imgui/imgui-SFML.h"
//Wonho
#include"../Includes/Resource.h"
#include"../Includes/Useful.h"

int main() {
	std::cout << "Success" << std::endl;
	std::cout << "Program Start!" << std::endl;

	//WON API
	Wonho_pp::Resource res("../../Resources");
	Wonho_pp::String_Helper StringHelper;
	Wonho_pp::Screen_Move ScreenHelper;
	ScreenHelper.setTileSize(90,90,2);

	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");
	//
	sf::Text text;
	sf::Font font;



	if (!font.loadFromFile(res.getPath("font.ttf")))
	{
		std::cout << "Font can't find\n";
	}
	text.setFont(font);
	text.setString(L"클릭하면 시작합니다.");
	text.setCharacterSize(24);
	ScreenHelper.setMiddle(text);
	text.setPosition(400, 20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	std::vector<sf::RectangleShape> sq;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			sq.push_back(ScreenHelper.setTile(i, j, sf::Color::Green));
		}
	}
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed) {
				text.setString(L"2 ^ 11");
				ScreenHelper.setMiddle(text);
			}
		}
			
		window.clear();
		for (auto i : sq) {
			window.draw(i);
		}
		window.draw(text);
		window.display();
	}

	std::cout << "Program End - Las\n";
	return 0;
}