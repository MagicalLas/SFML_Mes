/*************************************************************************
> File Name: Map.h
> Project Name: 2048 in GSM
> Author: ¿Ã¡§∫Û ,Wonho Ha aka Las
> Purpose: Main Map structure detinition
> Created Time: 2018/06/02
> Copyright (c) 2018, ¿Ã¡§∫Û
*************************************************************************/
#pragma once
#include "Define.h"

class Map
{
private:
	int Blank;
	int MapArray[VerticalMax][HorizontalMax];
	
public:
	Map()
	{
		Blank = VerticalMax * HorizontalMax;
		for (int i = 0; i < VerticalMax; i++)
			for (int j = 0; j < HorizontalMax; j++)
				MapArray[i][j] = 0;
	}
	bool IsFull();
	bool CheckEndGame();
	int ReturnBlank();
	bool AddBlank(int Num);
	int* operator[](int idx);
	void ShowMap();
};

