#include "block.h"
#include "position.h"

// LBlock class inherits from Block and represents an L-shaped Tetris block
class LBlock : public Block {
    public:
        // Constructor for LBlock, initializing the shape and initial position
        LBlock() {
            id = 1; // Set unique identifier for LBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0)};
            cells[3] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
            Move(0, 3); // Initial move to position the block correctly
        }
};

// JBlock class inherits from Block and represents a J-shaped Tetris block
class JBlock : public Block {
    public:
        // Constructor for JBlock, initializing the shape and initial position
        JBlock() {
            id = 2; // Set unique identifier for JBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 2), Position(1, 1), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1)};
            Move(0, 3); // Initial move to position the block correctly
        }
};

// IBlock class inherits from Block and represents an I-shaped Tetris block
class IBlock : public Block {
    public:
        // Constructor for IBlock, initializing the shape and initial position
        IBlock() {
            id = 3; // Set unique identifier for IBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
            cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
            cells[2] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
            cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
            Move(-1, 3); // Initial move to position the block correctly
        }
};

// OBlock class inherits from Block and represents an O-shaped Tetris block
class OBlock : public Block {
    public:
        // Constructor for OBlock, initializing the shape and initial position
        OBlock() {
            id = 4; // Set unique identifier for OBlock
            // Define the positions of the cells (OBlock doesn't rotate)
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1)};
            Move(0, 4); // Initial move to position the block correctly
        }
};

// SBlock class inherits from Block and represents an S-shaped Tetris block
class SBlock : public Block {
    public:
        // Constructor for SBlock, initializing the shape and initial position
        SBlock() {
            id = 5; // Set unique identifier for SBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2)};
            cells[2] = {Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1)};
            cells[3] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
            Move(0, 3); // Initial move to position the block correctly
        }
};

// TBlock class inherits from Block and represents a T-shaped Tetris block
class TBlock : public Block {
    public:
        // Constructor for TBlock, initializing the shape and initial position
        TBlock() {
            id = 6; // Set unique identifier for TBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
            Move(0, 3); // Initial move to position the block correctly
        }
};

// ZBlock class inherits from Block and represents a Z-shaped Tetris block
class ZBlock : public Block {
    public:
        // Constructor for ZBlock, initializing the shape and initial position
        ZBlock() {
            id = 7; // Set unique identifier for ZBlock
            // Define the positions of the cells in each rotation state
            cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
            cells[1] = {Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1)};
            cells[2] = {Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2)};
            cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0)};
            Move(0, 3); // Initial move to position the block correctly
        }
};
