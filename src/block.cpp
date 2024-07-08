#include "block.h"

// Constructor for the Block class, initializes default values
Block::Block()
{
    cellSize = 30;           // Size of each cell in pixels
    rotationState = 0;       // Initial rotation state
    colors = GetCellColors(); // Get the colors for the cells
    rowOffset = 0;           // Initial row offset
    columnOffset = 0;        // Initial column offset
}

// Draw the block at a given offset
void Block::Draw(int offsetX, int offsetY)
{
    std::vector<Position> tiles = GetCellPositions(); // Get the current cell positions
    for(Position item: tiles)
    {
        // Draw each cell with a 1-pixel gap between cells
        DrawRectangle(item.column * cellSize + offsetX, item.row * cellSize + offsetY, cellSize - 1, cellSize -1, colors[id]);
    }
}

// Move the block by a given number of rows and columns
void Block::Move(int rows, int columns)
{
    rowOffset += rows;       // Update the row offset
    columnOffset += columns; // Update the column offset
}

// Get the current positions of the cells in the block, taking into account the offset
std::vector<Position> Block::GetCellPositions()
{
    std::vector<Position> tiles = cells[rotationState]; // Get the cells for the current rotation state
    std::vector<Position> movedTiles;
    for(Position item: tiles)
    {
        // Calculate the new position with the offset
        Position newPos = Position(item.row + rowOffset, item.column + columnOffset);
        movedTiles.push_back(newPos); // Add the new position to the list
    }
    return movedTiles; // Return the list of moved positions
}

// Rotate the block to the next rotation state
void Block::Rotate()
{
    rotationState++; // Increment the rotation state
    if(rotationState == (int)cells.size())
    {
        rotationState = 0; // Wrap around if at the end of the rotation states
    }
}

// Undo the rotation of the block (rotate to the previous state)
void Block::UndoRotation()
{
    rotationState--; // Decrement the rotation state
    if(rotationState == -1)
    {
        rotationState = cells.size() - 1; // Wrap around if at the beginning of the rotation states
    }
}
