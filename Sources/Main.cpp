/*************************************************************************
> File Name: Main.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Main entry of 2048 Game
> Created Time: 2018/06/01
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/

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
	ScreenHelper.setMapSize(800, 800, 100);
	

	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");
	//	
	sf::Text text;
	std::vector<sf::Text> map_text;

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j  < 5; j++)
		{
			sf::Text t;
			res.setFont("font.ttf", t);
			ScreenHelper.setTextPosition(i, j, t, 20);
			map_text.push_back(t);
		}
	}
	res.setFont("font.ttf", text);
	text.setString(L"클릭하면 시작합니다.");
	text.setCharacterSize(24);
	ScreenHelper.setTextPosition(6, 1, text, 20);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	std::vector<sf::RectangleShape> sq;

	ScreenHelper.setMapTile(sq);

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
		for (auto i : map_text) {
			window.draw(i);
		}
		window.draw(text);
		window.display();
	}

	std::cout << "Program End - Las\n";
	return 0;
}