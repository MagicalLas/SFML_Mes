#pragma once
#include "Map.h"
#include "2048Define.h"

class MapControl
{
private:
	Map * ptr1;
#define PTR (*ptr1)

public:
	MapControl() :ptr1(nullptr) { };
	MapControl(Map *temp)
		: ptr1(temp)
	{
		for (int i = 0; i < Vertical; i++)
			for (int j = 0; j < Horizontal; j++)
				PTR[i][j] = 0;
		CreateBlock();
	}

	void InputMap(Map* NewMap);
	int AddBlock(int* BlockLine, int Count);
	void CreateBlock();
	void LeftKey();
	void RightKey();
	void UpKey();
	void DownKey();
};
