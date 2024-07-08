#include "game.h"  // Include the header file for Game class
#include <random>  // Include necessary headers

// Constructor: Initialize game state, load audio resources
Game::Game()
{
    grid = Grid();  // Initialize the game grid
    blocks = GetAllBlocks();  // Initialize the blocks vector with all available block types
    currentBlock = GetRandomBlock();  // Get the first random block for current gameplay
    nextBlock = GetRandomBlock();  // Get the next random block to show as preview
    gameOver = false;  // Set game over status to false
    score = 0;  // Initialize score to zero

    // Initialize audio system and load music and sound effects
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/beep.mp3");
    clearSound = LoadSound("Sounds/clear.mp3");
}

// Destructor: Unload audio resources and close audio device
Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}

// Generate a random block from the available blocks
Block Game::GetRandomBlock()
{
    // If blocks vector is empty, refill it with all available block types
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    
    // Generate a random index within the range of blocks vector
    int randomIndex = rand() % blocks.size();
    // Get the block at the random index
    Block block = blocks[randomIndex];
    // Remove the selected block from the vector to avoid repetition
    blocks.erase(blocks.begin() + randomIndex);
    // Return the random block
    return block;
}

// Return a vector containing all types of blocks used in the game
std::vector<Block> Game::GetAllBlocks()
{
    // Return a vector containing instances of all block types
    return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

// Draw the game grid, current block, and next block preview
void Game::Draw()
{
    grid.Draw();  // Draw the game grid
    currentBlock.Draw(11, 11);  // Draw the current block at a specific position

    // Draw the next block preview based on its type
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw(255, 290);
        break;
    case 4:
        nextBlock.Draw(255, 280);
        break;
    default:
        nextBlock.Draw(270, 270);
        break;
    }
}

// Handle player input for moving and rotating blocks
void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();  // Check for currently pressed key

    // If game over and any key is pressed, reset the game
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }

    // Handle different key presses for block movement and rotation
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        break;
    case KEY_UP:
        RotateBlock();
        break;
    }
}

// Move the current block left if possible
void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.Move(0, -1);
        // If block is outside grid boundaries or overlaps with another block, undo the move
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}

// Move the current block right if possible
void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.Move(0, 1);
        // If block is outside grid boundaries or overlaps with another block, undo the move
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

// Move the current block down if possible, lock it if it cannot move further
void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.Move(1, 0);
        // If block is outside grid boundaries or overlaps with another block, undo the move and lock the block
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
        }
    }
}

// Check if any part of the current block is outside the game grid boundaries
bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();  // Get positions of all cells in the current block

    // Check each cell position against the grid boundaries
    for (Position item : tiles)
    {
        // If any cell is outside the grid, return true
        if (grid.IsCellOutside(item.row, item.column))
        {
            return true;
        }
    }
    // If all cells are within grid boundaries, return false
    return false;
}

// Rotate the current block if possible
void Game::RotateBlock()
{
    if (!gameOver)
    {
        currentBlock.Rotate();  // Rotate the current block

        // If block is outside grid boundaries or overlaps with another block, undo the rotation
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
        else
        {
            PlaySound(rotateSound);  // Play a sound effect if rotation is successful
        }
    }
}

// Lock the current block into the grid and check for cleared rows
void Game::LockBlock()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();  // Get positions of all cells in the current block

    // Place each cell of the current block into the grid
    for (Position item : tiles)
    {
        grid.grid[item.row][item.column] = currentBlock.id;
    }

    // Set the next block to be the current block and check if it fits in the grid
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;  // If new block cannot fit in the grid, set game over status
    }

    nextBlock = GetRandomBlock();  // Get a new random block for the next block preview

    int rowsCleared = grid.ClearFullRows();  // Check for and clear any full rows in the grid
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);  // Play a sound effect if rows are cleared
        UpdateScore(rowsCleared, 0);  // Update the score based on cleared rows
    }
}

// Check if the current block fits within the grid without overlapping existing blocks
bool Game::BlockFits()
{
    std::vector<Position> tiles = currentBlock.GetCellPositions();  // Get positions of all cells in the current block

    // Check each cell position against the grid to ensure it's empty
    for (Position item : tiles)
    {
        // If any cell overlaps with an existing block in the grid, return false
        if (grid.isCellEmpty(item.row, item.column) == false)
        {
            return false;
        }
    }
    // If all cells fit within empty grid cells, return true
    return true;
}

// Reset the game to its initial state
void Game::Reset()
{
    grid.Initilize();  // Reset the game grid to its initial state
    blocks = GetAllBlocks();  // Refill the blocks vector with all available block types
    currentBlock = GetRandomBlock();  // Get a new random block for current gameplay
    nextBlock = GetRandomBlock();  // Get a new random block for the next block preview
    score = 0;  // Reset the score to zero
}

// Update the player's score based on lines cleared and movement points
void Game::UpdateScore(int LinesCleared, int moveDownPoints)
{
    // Update the score based on the number of lines cleared
    switch (LinesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;  // Add additional points for moving blocks down
}
