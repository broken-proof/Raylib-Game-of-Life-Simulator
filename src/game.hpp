#pragma once
#include "grid.hpp"
#include <raylib.h>
class Game
{
public:
  Game(int width, int height, int cellSize)
      : grid(width, height, cellSize), temp(width, height, cellSize), run(false) {};
  void Draw(Color col);
  void updateCell(int row, int column, int value);
  int howManyNeighbors(int row, int column);
  void updateGame();
  bool isRunning();
  void Start() { run = true; };
  void Stop() { run = false; };
  void change(int row, int col, bool left);
  void clearGame()
  {
    if (!isRunning())
    {
      grid.Clear();
    }
  }
  void RandomState();

private:
  Grid grid;
  Grid temp;
  bool run;
};