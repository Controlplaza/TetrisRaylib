#include "block.h"
using namespace std;
Block::Block() 
{
	cellSize = 30;
	rotationState = 0;
	rowOffset = 0;
	columnOffset = 0;
}

/// <summary>
/// Draws the indivdual blocks on screen
/// </summary>
/// <param name="offsetX"></param>
/// <param name="offsetY"></param>
void Block::Draw(int offsetX,int offsetY) 
{
	vector<Position> tiles = GetCellPositions();
	for (Position item : tiles)
	{
		DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors[blockID]);

	}
}

/// <summary>
/// Function that moves the blocks
/// </summary>
/// <param name="rows"></param>
/// <param name="columns"></param>
void Block::Move(int rows, int columns) 
{
	rowOffset += rows;
	columnOffset += columns;
}

vector<Position> Block::GetCellPositions()
{
	vector<Position> tiles = cells[rotationState];
	vector<Position> movedTiles;
	for (Position item : tiles)
	{
		Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
		movedTiles.push_back(newPos);
	}
}