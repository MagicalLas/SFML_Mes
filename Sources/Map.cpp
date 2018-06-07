/*************************************************************************
> File Name: Map.cpp
> Project Name: 2048 in GSM
> Author: ¿Ã¡§∫Û ,Wonho Ha aka Las
> Purpose: Main Map Implimentation
> Created Time: 2018/06/02
> Copyright (c) 2018, ¿Ã¡§∫Û
*************************************************************************/
#include "../Includes/Map.h"

#include <iostream>
using namespace std;

bool Map::IsFull()
{
	if(Blank == 0)	return true;
	return false;
}

bool Map::CheckEndGame()
{
	for(int i = 0; i < VerticalMax; i++)
	{ 
		for (int j = 0; j < HorizontalMax-1; j++)
		{
			if (MapArray[i][j] == MapArray[i][j + 1])
			{
				return false;
			}

		}
	}
	for (int i = 0; i < HorizontalMax; i++)
	{
		for (int j = 0; j < VerticalMax - 1; j++)
		{
			if (MapArray[j][i] == MapArray[j+1][i])
			{
				return false;
			}

		}
	}

	return true;
}

int Map::ReturnBlank()
{
	return Blank;
}

bool Map::AddBlank(int Num)
{
	if (Blank + Num > VerticalMax * HorizontalMax || Blank + Num < 0)
	{
		cout << "Blank¿« π¸¿ß∏¶ π˛æÓ≥≥¥œ¥Ÿ." << endl;
		return false;
	}
	Blank += Num;
	return true;
	
}

int * Map::operator[](int idx)
{
	if (idx >= VerticalMax || idx < 0)
	{
		cout << "Map Index Error";
		return nullptr;
	}
	return MapArray[idx];
}

void Map::ShowMap()
{
	for (int i = 0; i < VerticalMax; i++)
	{
		for (int j = 0; j < HorizontalMax; j++)
		{
			cout << MapArray[i][j] << " ";
		}
		cout << endl;
	}
}