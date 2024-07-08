#include "position.h"  // Include the header file where Position class is declared

// Constructor implementation for Position class
Position::Position(int row, int column)
{
    // Initialize the object's row and column members with provided values
    this->row = row;
    this->column = column;
}

// Note: Assuming Position class has member variables `row` and `column`,
//       and they are initialized using constructor initialization list.
//       Alternatively, could use member initializer list as follows:

// Position::Position(int row, int column) : row(row), column(column)
// {
//     // Constructor body is empty because member initializer list already initializes members
// }
