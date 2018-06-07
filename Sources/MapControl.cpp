/*************************************************************************
> File Name: MapControl.cpp
> Project Name: 2048 in GSM
> Author: 이정빈 ,Wonho Ha aka Las
> Purpose: Map Controller for Game Play
> Created Time: 2018/05/29
> Copyright (c) 2018, 이정빈
*************************************************************************/
#include "../Includes/MapControl.h"
#include "../Includes/Define.h"
#include <iostream>
using namespace std;

void MapControl::InputMap(Map * NewMap)
{
	if (NewMap != nullptr)
	{
		cout << "NULL 값으로 초기화 할수 없습니다." << endl;
		exit(1);
	}
	ptr1 = NewMap;
}

bool MapControl::AddBlock(int *BlockLine, int Count, int Direction)
{

	if (Direction == 1) {
		int Input_place = 0;
		for (int i = 0; i < Count; i++)
		{
			if (BlockLine[i] == BlockLine[i + 1] && i != Count - 1)
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i] + BlockLine[i + 1];
					BlockLine[i] = 0;
					BlockLine[i + 1] = 0;
					BlockLine[Input_place++] = Temp;
					PTR.AddBlank(1);
				}
				i++;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i];
					BlockLine[i] = 0;
					BlockLine[Input_place] = Temp;
					Input_place++;
				}
				
			}
		}
		return true; // 마지막 데이터가 있는 Index 위치;
	}
	else if (Direction == -1)
	{
		bool MoveCheck = false;
		int Input_place = Count - 1;
		for (int i = Count - 1; i >= 0; i--)
		{
			if (BlockLine[i] == BlockLine[i - 1] && i != 0)
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i] + BlockLine[i - 1];
					BlockLine[i] = 0;
					BlockLine[i - 1] = 0;
					BlockLine[Input_place--] = Temp;
					PTR.AddBlank(1);
					MoveCheck = true;
				}
				i--;
			}
			else
			{
				if (BlockLine[i] != 0)
				{
					int Temp = BlockLine[i];
					BlockLine[i] = 0;
					BlockLine[Input_place--] = Temp;
				}
			}
		}
	}
}

bool MapControl::PushKey(int Key)
{
	if (ptr1 == nullptr)
	{
		cout << "MapControl의 Map을 초기화 시켜주세요." << endl;
		exit(1);
	}

	int BlockLineMax;
	int KeyType;
	int Direction;
	if (Key / Horizontal == -1 || Key / Horizontal == 1)
	{
		BlockLineMax = HorizontalMax;
		KeyType = Horizontal;
		Direction = Key / Horizontal;
	}
	else if(Key / Vertical == -1 || Key / Vertical == 1)
	{
		BlockLineMax = VerticalMax;
		KeyType = Vertical;
		Direction = Key / Vertical;
	}
	else
	{
		cout << "잘못된 키값이 PushKey()함수에 전달되었습니다. Key : " << Key << endl;
		exit(1);
	}
	cout << endl << "KeyType : " << KeyType << " Direction : " << Direction << " BlockLineMax : " << BlockLineMax <<endl;
	bool MoveCheck = false;
	int BlockCount = 0;
	int* BlockLine = (int*)malloc(sizeof(int)*BlockLineMax);

	for (int i = 0; i < (KeyType == Vertical ? HorizontalMax : VerticalMax); i++)
	{
		BlockCount = 0;
		for (int j = 0; j < BlockLineMax; j++)
		{
			if (KeyType == Vertical)
			{
				if (PTR[i][j] != 0) {
					BlockLine[BlockCount++] = PTR[i][j];
				}
			}
			else
			{
				if (PTR[j][i] != 0)
					BlockLine[BlockCount++] = PTR[j][i];
			}
		}
		for (int j = BlockCount; j < BlockLineMax; j++)
			BlockLine[j] = 0;
		MoveCheck = AddBlock(BlockLine, BlockLineMax, Direction);
		for (int j = 0; j < BlockLineMax; j++)
		{
			if (KeyType == Vertical)
			{
				PTR[i][j] = BlockLine[j];
			}
			else 
			{
				PTR[j][i] = BlockLine[j];
			}
		}
	}
	free(BlockLine);
	return MoveCheck;
}

void MapControl::CreateBlock()
{

	if (ptr1 == nullptr)
	{
		cout << "MapControl의 Map을 초기화 시켜주세요." << endl;
		exit(1);
	}
	if (PTR.IsFull())
	{
		return;
	}

	int Randomi, Randomj;
	do
	{
		Randomi = rand() % VerticalMax;
		Randomj = rand() % HorizontalMax;
	} while (PTR[Randomi][Randomj] != 0);

	int RandResult = rand() % 10;
	if (RandResult == 1) PTR[Randomi][Randomj] = 4;
	else PTR[Randomi][Randomj] = 2;
	PTR.AddBlank(-1);
	
}