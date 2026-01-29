#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
  Grid(int width, int height, int cellSize)
      : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {}; // Initialize grid with blank squares
  void Draw(Color col);

  // Make cell editability public
  void updateCell(int row, int column, int value);

  // get values
  int getValue(int row, int column);

  // get attributes
  int TotalRows() { return rows; };
  int TotalColumns() { return columns; };

  void randomFill();
  void Clear();

private:
  int rows;
  int columns;
  int cellSize;
  std::vector<std::vector<int>> cells;
};