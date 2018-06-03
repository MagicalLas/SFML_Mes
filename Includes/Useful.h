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
		int map[5][5] = {-1,};
		void setMiddle(sf::Text& draw);
		sf::RectangleShape setTile(int x, int y, sf::Color color);
		void setTextPosition(int x, int y, sf::Text& draw, int number);
		void setTextNum(int number, sf::Text & draw);
		void setTileSize(int x, int y, int r);
		void setMapSize(int x, int y, int b);
		void setMapTile(std::vector<sf::RectangleShape> &vec);
		void UpdateMapText(std::vector<sf::Text> &vec);
	};
	struct String_Helper
	{
		std::wstring Korean(std::string str);
	};
};