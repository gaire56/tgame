#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

// Block class represents a Tetris-like block with various operations
class Block
{
    public:
        Block(); // Constructor to initialize the Block
        void Draw(int offsetX, int offsetY); // Draw the block at given offsets
        void Move(int rows, int columns); // Move the block by specified rows and columns
        std::vector<Position> GetCellPositions(); // Get the current positions of the block's cells
        void Rotate(); // Rotate the block to the next state
        void UndoRotation(); // Undo the rotation (rotate to the previous state)
        
        int id; // Identifier for the block
        std::map<int, std::vector<Position>> cells; // Map of rotation states to cell positions

    private:
        int cellSize; // Size of each cell in pixels
        int rotationState; // Current rotation state of the block
        std::vector<Color> colors; // Colors of the cells
        int rowOffset; // Row offset for the block's position
        int columnOffset; // Column offset for the block's position
};
