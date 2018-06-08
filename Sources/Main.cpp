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
//Wonho
#include"../Includes/Resource.h"
#include"../Includes/Useful.h"
//정빈
#include"../Includes/Map.h"
#include"../Includes/MapControl.h"
#include"../Includes/Define.h"
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
	MapController.CreateBlock();

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
	
	
	for (size_t i = 0; i < MapSize; i++)
	{
		for (size_t j = 0; j < MapSize; j++)
		{
			sf::Text t = *new(sf::Text);
			res.setFont("font.ttf", t);
			ScreenHelper.setTextPosition(j, i, t);
			map_text.push_back(t);
		}
	}
	display.UpdateMap(map);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			bool MoveCheck = true;

			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed) {

				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					MoveCheck = MapController.PushKey(UpKey);
					if (MoveCheck) MapController.CreateBlock();
					break;
				case sf::Keyboard::Down:
					MoveCheck = MapController.PushKey(DownKey);
					if (MoveCheck) MapController.CreateBlock();
					break;
				case sf::Keyboard::Left:
					MoveCheck = MapController.PushKey(LeftKey);
					if (MoveCheck) MapController.CreateBlock();
					break;
				case sf::Keyboard::Right:
					MoveCheck = MapController.PushKey(RightKey);
					if (MoveCheck) MapController.CreateBlock();
					break;
				default:
					break;
				}
				
				display.UpdateMap(map);
				display.UpdateMapText(map_text);
				display.UpdateMapTile(map_tile);
			}
			if (event.type == event.MouseButtonPressed) {
				text.setString(L"2 ^ 11");
				ScreenHelper.setMiddle(text);
			}
			if (!MoveCheck) {
				if(map.ReturnState()==PlayerLose)
					text.setString(L"패배했습니다.");
				if (map.ReturnState() == PlayerWin)
					text.setString(L"승리했습니다.");
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