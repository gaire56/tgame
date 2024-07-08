// Prevents multiple inclusions of this header file during compilation
#pragma once

// Includes necessary headers for Raylib and std::vector
#include <raylib.h>
#include <vector>

// Declaration of external constants representing colors
extern const Color darkGray;
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightBlue;
extern const Color darkBlue;

// Declaration of a function that returns a vector of Color objects
std::vector<Color> GetCellColors();
