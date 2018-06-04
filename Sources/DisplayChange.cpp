#include"../Includes/Useful.h"

void Wonho_pp::DisplayChange::UpdateMapText(std::vector<sf::Text>& vec)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			vec[i * 5 + j].setCharacterSize(10);
		}
	}
}
void Wonho_pp::DisplayChange::UpdateMapTile(std::vector<sf::RectangleShape>& vec)
{
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			vec[i * 5 + j].setFillColor(sf::Color::Blue);
		}
	}
};