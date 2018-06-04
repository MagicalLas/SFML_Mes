#include "../Includes/Map.h"

#include <iostream>
using namespace std;

int * Map::operator[](int idx)
{
	if (idx >= Vertical || idx < 0)
	{
		cout << "Map Index Error";
		return nullptr;
	}
	return MapArray[idx];
}

void Map::ShowMap()
{
	for (int i = 0; i < Vertical; i++)
	{
		for (int j = 0; j < Horizontal; j++)
		{
			cout << MapArray[i][j] << " ";
		}
		cout << endl;
	}
}