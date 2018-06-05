#pragma once
#include "Map.h"

class MapControl
{

private:
	#define PTR (*ptr1)
	Map *ptr1;
	bool AddBlock(int* BlockLine, int Count, int Direction);

public:

	MapControl() :ptr1(nullptr) { }
	MapControl(Map *temp) : ptr1(temp) { }

	bool PushKey(int Key);
	void CreateBlock();
	void InputMap(Map* NewMap);

};
