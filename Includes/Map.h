#pragma once
#include "Define.h"

class Map
{
private:
	int Blank;
	int MapArray[Vertical][Horizontal];

public:
	Map()
	{
		Blank = Vertical * Horizontal;
		for (int i = 0; i < Vertical; i++)
			for (int j = 0; j < Horizontal; j++)
				MapArray[i][j] = 0;
	}
	int* operator[](int idx);
	void ShowMap();
};

