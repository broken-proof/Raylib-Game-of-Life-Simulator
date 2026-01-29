#include <raylib.h>
#include "grid.hpp"
#include "game.hpp"
#include <iostream>
int main()
{
  Color GREY = {29, 29, 29, 225};

  const int width = 1500, height = 750;
  int FPS = 10;
  int size = 15;
  float hue = 180;
  // Initialize window
  InitWindow(width, height, "Conway's Game of Life Running...");

  // Initialize Settings
  SetTargetFPS(FPS);

  // Make game object
  Game board(width, height, size);

  // Simulation Loop
  while (WindowShouldClose() == false)
  {
    // ***********Event Handeling***********
    // Mouse
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
      Vector2 mouse = GetMousePosition();
      if (!board.isRunning())
      {
        int row = mouse.y / size;
        int col = mouse.x / size;
        board.change(row, col, true);
      }
    }
    else if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
    {
      Vector2 mouse = GetMousePosition();
      if (!board.isRunning())
      {
        int row = mouse.y / size;
        int col = mouse.x / size;
        board.change(row, col, false);
      }
    }

    // Keyboard

    if (IsKeyPressed(KEY_ENTER))
    {
      board.Start();
    }
    else if (IsKeyPressed(KEY_SPACE))
    {
      board.Stop();
    }
    else if (IsKeyPressed(KEY_UP))
    {
      if (FPS < 15)
      {
        FPS++;
        SetTargetFPS(FPS);
      }
    }
    else if (IsKeyPressed(KEY_DOWN))
    {
      if (FPS > 3)
      {
        FPS--;
        SetTargetFPS(FPS);
      }
    }
    else if (IsKeyPressed(KEY_R))
    {
      board.RandomState();
    }
    else if (IsKeyPressed(KEY_C))
    {
      board.clearGame();
    }
    else if (IsKeyDown(KEY_RIGHT))
    {
      hue += 1.0f;
    }
    else if (IsKeyDown(KEY_LEFT))
    {
      hue -= 1.0f;
    }

    if (hue > 360)
    {
      hue = 0;
    }
    if (hue < 0)
    {
      hue = 360;
    }
    //*********** Update Grid State ***********
    board.updateGame();

    //*********** Draw New State ***********
    BeginDrawing();
    ClearBackground(GREY);
    board.Draw(ColorFromHSV(hue, 1.0f, 1.0f));
    EndDrawing();
  }

  CloseWindow();
}