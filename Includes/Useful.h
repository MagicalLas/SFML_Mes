#pragma once
#include"SFML\Graphics.hpp"
#include"Resource.h"
#include<iostream>
#include<string>
#include<vector>
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
	public:
		Screen_Move();
		int map[5][5] = {-1,};
		void setMiddle(sf::Text& draw);
		sf::RectangleShape setTile(int x, int y, sf::Color color);
		void setTileSize(int x, int y, int r);
		void setMapSize(int x, int y, int b);
		
	};
	struct String_Helper
	{
		std::wstring Korean(std::string str);
	};
};