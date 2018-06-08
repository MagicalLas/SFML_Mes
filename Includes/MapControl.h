#pragma once
#include "Map.h"

class MapControl
{

private:
	#define PTR (*ptr1)
	Map *ptr1;
	void AddBlock(int* BlockLine, int Count, int Direction);
	bool MoveChecking(int* BeforeMoving, int* AfterMoving, int Count);
public:

	MapControl() :ptr1(nullptr) { }
	MapControl(Map *temp) : ptr1(temp) { }

	bool PushKey(int Key);
	void CreateBlock();
	void InputMap(Map* NewMap);

};
