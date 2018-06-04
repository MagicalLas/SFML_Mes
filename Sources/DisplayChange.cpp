#include"../Includes/Useful.h"

[[noreturn]]void Wonho_pp::DisplayChange::UpdateMapText(std::vector<sf::Text>& vec)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			vec[i * 5 + j].setCharacterSize(10);
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