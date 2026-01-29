#include "grid.hpp"
#include <raylib.h>
#include <ctime>
#include <cstdlib>

void Grid::Draw(Color col)
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      Color color;
      if (cells[row][column] == 1)
      {
        color = col;
      }
      else
      {
        color = Color{55, 55, 55, 255};
      }
      DrawRectangle(column * cellSize, row * cellSize, cellSize - 2, cellSize - 2, color);
    }
  }
}

void Grid::updateCell(int row, int column, int value)
{

  if ((row >= 0 && row <= rows) && (column >= 0 && column <= columns))
  {
    cells[row][column] = value;
  }
}

int Grid::getValue(int row, int column)
{
  if ((row >= 0 && row <= rows) && (column >= 0 && column <= columns))
  {
    return cells[row][column];
  }
  return -1;
}

void Grid::randomFill()
{
  srand(time(NULL));
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < columns; col++)
    {
      int val = rand() % 5;
      if (val == 1)
      {
        cells[row][col] = 1;
      }
      else
      {
        cells[row][col] = 0;
      }
    }
  }
}

void Grid::Clear()
{
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < columns; col++)
    {
      cells[row][col] = 0;
    }
  }
}
