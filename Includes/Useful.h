/*************************************************************************
> File Name: Useful.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Some Usefull functions.
> Created Time: 2018/05/28
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/
#pragma once
#include"SFML\Graphics.hpp"
#include"Resource.h"
#include"Map.h"
#include"../Includes/Resource.h"
#include<iostream>
#include<string>
#include<vector>
#include<tuple>
namespace Wonho_pp {
	class Screen_Move
	{
	private:
		int tile_x;
		int tile_y;
		int round;
		int map_x;
		int map_y;
		int yBolder; 
		sf::Text t;
		std::tuple<int, int> PositionFunc(int x, int y);
	public:
		Screen_Move();
		void setMiddle(sf::Text& draw);
		sf::RectangleShape setTile(int x, int y, sf::Color color);
		void setTextPosition(int x, int y, sf::Text& draw);
		void setTileSize(int x, int y, int r);
		void setMapSize(int x, int y, int b);
		void setMapTile(std::vector<sf::RectangleShape> &vec);
		
	};
	class DisplayChange
	{
	private:
		std::vector<int> map;
		void setTextNum(int number, sf::Text & draw);
		Screen_Move SM;
	public:
		[[noreturn]]void UpdateMap(Map map);
		[[noreturn]]void UpdateMapText(std::vector<sf::Text> &vec);
		[[noreturn]]void UpdateMapTile(std::vector<sf::RectangleShape> &vec);
		void setRecColor(sf::RectangleShape& draw, int num) {
			switch (num)
			{
			case 0:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 00));
				break;
			case 2:
				draw.setFillColor(sf::Color::Color(2, 65, 40, 255));
				break;
			case 4:
				draw.setFillColor(sf::Color::Color(255, 65, 23, 255));
				break;
			case 8:
				draw.setFillColor(sf::Color::Color(2, 65, 255, 255));
				break;
			case 16:
				draw.setFillColor(sf::Color::Color(255, 205, 23, 255));
				break;
			case 32:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 64:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 128:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 256:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 512:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 1024:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			case 2048:
				draw.setFillColor(sf::Color::Color(2, 65, 23, 255));
				break;
			default:
				break;
			}

		}
	};
};