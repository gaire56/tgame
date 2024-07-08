#pragma once  // Ensures this header file is included only once during compilation

#include "grid.h"  // Include the definition of Grid class
#include "blocks.cpp"  // Include the implementation of different Block types

class Game
{
public:
    // Constructor and Destructor
    Game();  // Initialize game state
    ~Game();  // Clean up resources

    // Methods for game logic
    void Draw();  // Draw the game elements
    void HandleInput();  // Handle player input
    void MoveBlockDown();  // Move the current block down

    // Public member variables
    bool gameOver;  // Indicates whether the game is over
    int score;  // Current score of the player
    Music music;  // Music stream for game background music

private:
    // Private methods for internal use
    void MoveBlockLeft();  // Move the current block left
    void MoveBlockRight();  // Move the current block right
    Block GetRandomBlock();  // Generate a random block
    std::vector<Block> GetAllBlocks();  // Get all block types
    bool IsBlockOutside();  // Check if the current block is outside the grid
    void RotateBlock();  // Rotate the current block
    void LockBlock();  // Lock the current block into the grid
    bool BlockFits();  // Check if the current block fits in the grid
    void Reset();  // Reset the game state
    void UpdateScore(int LinesCleared, int moveDownPoints);  // Update the player's score

    // Private member variables
    Grid grid;  // Game grid
    std::vector<Block> blocks;  // Available block types
    Block currentBlock;  // Current active block
    Block nextBlock;  // Next block to appear
    Sound rotateSound;  // Sound effect for block rotation
    Sound clearSound;  // Sound effect for clearing rows
};
