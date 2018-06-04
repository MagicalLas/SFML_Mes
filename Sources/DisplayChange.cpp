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
	for (size_t y = 0; y < 5; y++)
	{
		for (size_t x = 0; x < 5; x++)
		{
			setTextNum(y + 10*x, vec[y * 5 + x]);
			SM.setMiddle(vec[y * 5 + x]);
		}
	}
}
[[noreturn]]void Wonho_pp::DisplayChange::UpdateMapTile(std::vector<sf::RectangleShape>& vec)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			vec[i * 5 + j].setFillColor(sf::Color::Blue);
		}
	}
};
[[noreturn]]void Wonho_pp::DisplayChange::UpdateMap(int map_[5][5]) {
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			map[i * 5 + j] = map_[i][j];
		}
	}
}
void Wonho_pp::DisplayChange::setTextNum(int number, sf::Text & draw)
{
	std::string s = "";
	if (number != 0)
		s = std::to_string(number);
	draw.setString(s);
};