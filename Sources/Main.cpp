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
//정빈
#include"../Includes/Map.h"
#include"../Includes/MapControl.h"
#include"../Includes/2048Define.h"
int main() {
	std::cout << "Success" << std::endl;
	std::cout << "Program Start!" << std::endl;

	//WON API
	Wonho_pp::Resource res("../../Resources");
	Wonho_pp::DisplayChange display;
	Wonho_pp::Screen_Move ScreenHelper;

	//Jeungbin
	Map map;
	MapControl MapController(&map);
	
	ScreenHelper.setTileSize(90,90,2);
	ScreenHelper.setMapSize(800, 800, 100);
	

	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");
	//	
	sf::Text text;
	std::vector<sf::Text> map_text;

	
	res.setFont("font.ttf", text);
	text.setString(L"클릭하면 시작합니다.");
	text.setCharacterSize(24);
	ScreenHelper.setMiddle(text);
	text.setPosition(400, 200);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	std::vector<sf::RectangleShape> map_tile;

	ScreenHelper.setMapTile(map_tile);
	
	
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			sf::Text t = *new(sf::Text);
			res.setFont("font.ttf", t);
			ScreenHelper.setTextPosition(j, i, t);
			map_text.push_back(t);
		}
	}
	map[2][3] = 16;
	display.UpdateMap(map);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up)
					MapController.UpKey();
				else if (event.key.code == sf::Keyboard::Down)
					MapController.DownKey();
				else if (event.key.code == sf::Keyboard::Left)
					MapController.LeftKey();
				else if (event.key.code == sf::Keyboard::Right)
					MapController.RightKey();
				//MapController.CreateBlock();
				//bool isPull = 
				//if (isPull)
					//break;
				display.UpdateMap(map);
				display.UpdateMapText(map_text);
				display.UpdateMapTile(map_tile);
			}
			if (event.type == event.MouseButtonPressed) {
				text.setString(L"2 ^ 11");
				ScreenHelper.setMiddle(text);
			}
		}
			
		window.clear();
		for (auto i : map_tile) {
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