/*************************************************************************
> File Name: DisplayChange.cpp
> Project Name: 2048 in GSM
> Author: ¿Ã¡§∫Û
> Purpose: Display Update with Map
> Created Time: 2018/06/04
> Copyright (c) 2018, ¿Ã¡§∫Û
*************************************************************************/
#include "../Includes/Map.h"
#include <iostream>
using namespace std;

int * Map::operator[](int idx)
{
	if (idx >= Vertical)
	{
		cout << "Map Index Error";
		return NULL;
	}
	return MapArray[idx];
}

[[deprecated]]
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