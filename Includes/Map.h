#pragma once
#include "2048Define.h"

class Map
{
private:
	int MapArray[Vertical][Horizontal];

public:
	int* operator[](int idx);
	void ShowMap();
};