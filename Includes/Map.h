#pragma once
#include "Define.h"

class Map
{
private:
	int GameState;
	int Blank;
	int MapArray[VerticalMax][HorizontalMax];
	
public:
	Map()
		:GameState(GameContinue), Blank(VerticalMax * HorizontalMax)
	{
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
	void EndGame(int EndCode);
	int ReturnState();
};

