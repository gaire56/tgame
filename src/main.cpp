#include <raylib.h>      // Including Raylib library for graphics and input handling
#include "game.h"        // Including user-defined game logic header
#include "colors.h"      // Including user-defined color definitions header
#include <iostream>      // Standard input-output stream

double lastUpdateTime = 0; // Variable to track last update time for event triggering

// Function to check if a certain time interval has elapsed since the last event
bool EventTriggered(double interval)
{
    double currentTime = GetTime();  // Get current time using Raylib's function
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime; // Update last update time
        return true;                  // Return true if interval has passed
    }
    return false;                     
}

// Main function where program execution starts
int main()
{
    InitWindow(500, 620, "GAIRE ANANTA PRASAD M24W0272"); // Initialize window
    SetTargetFPS(60);                                      // Set target frames per second for the application

    Font font = LoadFontEx("Font/monogram.otf", 64, 0, 0);  // Load a custom font for text rendering

    Game game = Game();    // Initialize an instance of the Game class for game logic

    // Main application loop
    while(WindowShouldClose() == false)  // Continue looping until the user closes the window
    {
        UpdateMusicStream(game.music);   // Update game music
        game.HandleInput();              // Handle user input
        if(EventTriggered(0.2))          // Check if 0.2 seconds have passed since the last update
        {
            game.MoveBlockDown();        // If true, move the game block down
        }
        BeginDrawing();                  // Begin drawing the frame

        ClearBackground(darkBlue);       // Clear the background with a specified color

        // Draw text for 'Score' and 'Next' sections
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);

        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER", {320, 450}, 38, 2, WHITE); // Draw 'GAME OVER' if the game is over
        }

        // Draw rounded rectangles for the score and next piece sections
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);

        // Convert score to text and draw it centered within the score rectangle
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);  // Format score as string
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2); // Measure size of score text
        DrawTextEx(font, scoreText, {320 + (170 - textSize.x)/2, 65}, 38, 2, WHITE);

        game.Draw();    // Draw game objects and elements

        EndDrawing();   // End drawing the frame
    }

    CloseWindow();  // Close the application window and free resources

    return 0;
}
