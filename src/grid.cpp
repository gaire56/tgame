#include "grid.h"  // Include the header file for Grid class
#include <iostream>  // Include for std::cout and std::endl
#include "colors.h"  // Include for GetCellColors function

// Constructor: Initialize grid dimensions, cell size, and colors
Grid::Grid()
{
    numRows = 20;  // Number of rows in the grid
    numCols = 10;  // Number of columns in the grid
    cellSize = 30;  // Size of each cell in pixels
    Initilize();  // Initialize the grid to all zeros (empty)
    colors = GetCellColors();  // Get colors for drawing cells
}

// Initialize the grid to all zeros (empty)
void Grid::Initilize()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            grid[row][column] = 0;  // Set each cell to zero (empty)
        }
    }
}

// Print the grid (for debugging purposes)
void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";  // Output cell value
        }
        std::cout << std::endl;  // Move to the next line after each row
    }
}

// Draw the grid on the screen
void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            int cellValue = grid[row][column];  // Get value of the current cell
            // Draw a rectangle representing the cell with appropriate color
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

// Check if a cell is outside the boundaries of the grid
bool Grid::IsCellOutside(int row, int column)
{
    // Check if the given row and column are within the grid boundaries
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;  // Cell is inside the grid
    }
    return true;  // Cell is outside the grid
}

// Check if a cell in the grid is empty (contains value 0)
bool Grid::isCellEmpty(int row, int column)
{
    // Check if the cell at the given row and column is empty (value is 0)
    if (grid[row][column] == 0)
    {
        return true;  // Cell is empty
    }
    return false;  // Cell is not empty
}

// Clear all cells in a full row and move rows above it down
int Grid::ClearFullRows()
{
    int completed = 0;  // Counter for number of completed rows cleared

    // Traverse the grid from bottom to top
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);  // Clear the full row
            completed++;  // Increment completed rows counter
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);  // Move rows above down by 'completed' rows
        }
    }
    return completed;  // Return number of completed rows cleared
}

// Check if a specific row is completely filled (no empty cells)
bool Grid::IsRowFull(int row)
{
    // Check each cell in the specified row
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;  // Found an empty cell, row is not full
        }
    }
    return true;  // All cells in the row are filled, row is full
}

// Clear all cells in a specific row (set them to zero)
void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;  // Set each cell in the row to zero
    }
}

// Move all cells in a specific row down by a given number of rows
void Grid::MoveRowDown(int row, int numRows)
{
    // Traverse each cell in the row from top to bottom
    for (int column = 0; column < numCols; column++)
    {
        // Move cell contents 'numRows' rows down in the grid
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;  // Clear the original cell after moving its contents
    }
}
