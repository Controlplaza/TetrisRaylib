#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"
using namespace std;

class Block
{
public:
	Block();
	void Draw (int offsetX,int offsetY);
	void Move(int rows, int columns);
	void Rotate();
	void UndoRotation();
	vector<Position>GetCellPositions();
	int blockID;
	map<int, vector<Position>> cells;


private:

};

Block::Block()
{
}

