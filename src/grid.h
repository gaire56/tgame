#pragma once  // Ensures this header file is included only once during compilation

#include <vector>   // Include for std::vector
#include <raylib.h> // Include for Raylib library functions and types

class Grid
{
public:
    Grid();  // Constructor
    void Initilize();  // Initialize the grid
    void Print();  // Print the grid (for debugging)
    void Draw();  // Draw the grid on the screen
    bool IsCellOutside(int row, int column);  // Check if a cell is outside the grid
    bool isCellEmpty(int row, int column);  // Check if a cell is empty
    int ClearFullRows();  // Clear all full rows and move rows above down

    int grid[20][10];

private:
    bool IsRowFull(int row);  // Check if a specific row is completely filled
    void ClearRow(int row);  // Clear all cells in a specific row
    void MoveRowDown(int row, int numRows);  // Move all cells in a specific row down

    int numRows;  // Number of rows in the grid
    int numCols;  // Number of columns in the grid
    int cellSize;  // Size of each cell in pixels
    std::vector<Color> colors;  // Vector to store colors for drawing cells
};
