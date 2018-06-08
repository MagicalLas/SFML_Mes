/*************************************************************************
> File Name: DisplayChange.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Display Update with Map
> Created Time: 2018/06/04
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/

#include"../Includes/Useful.h"
[[noreturn]]void Wonho_pp::DisplayChange::UpdateMapText(std::vector<sf::Text>& vec)
{
	for (size_t x = 0; x < MapSize; x++)
	{
		for (size_t y = 0; y < MapSize; y++)
		{
			setTextNum(map[y * MapSize + x], vec[y * MapSize + x]);
			SM.setMiddle(vec[y * MapSize + x]);
		}
	}
}
[[noreturn]]void Wonho_pp::DisplayChange::UpdateMapTile(std::vector<sf::RectangleShape>& vec)
{
	for (size_t j = 0; j < MapSize; j++)
	{
		for (size_t i = 0;i < MapSize; i++)
		{
			setRecColor(vec[i * MapSize + j], map[i * MapSize + j]);
		}
	}
};
[[noreturn]]void Wonho_pp::DisplayChange::UpdateMap(Map map_) {
	map.clear();
	std::cout << "\n====================\n";
	for (size_t i = 0; i < MapSize; i++)
	{
		for (size_t j = 0; j < MapSize; j++)
		{
			std::cout << map_[i][j] << ", ";
			map.push_back(map_[i][j]);
		}
		std::cout << "\n";
	}
}
void Wonho_pp::DisplayChange::setTextNum(int number, sf::Text & draw)
{
	std::string s = "";
	if (number != 0)
		s = std::to_string(number);
	draw.setString(s);
};