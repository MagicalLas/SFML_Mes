#pragma once
#include "../Includes/Map.h"

class MapControl
{

private:
	#define PTR (*ptr1)
	Map *ptr1;
	int AddBlock(int* BlockLine, int Count, int Direction = 1);

public:
	MapControl() :ptr1(nullptr) { }
	MapControl(Map *temp) : ptr1(temp) { }

	void InputMap(Map* NewMap);
	void CreateBlock();
	void LeftKey();
	void RightKey();
	void UpKey();
	void DownKey();

};
