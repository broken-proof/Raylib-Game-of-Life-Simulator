#include "game.hpp"
#include <utility>
#include <ctime>
#include <raylib.h>
using namespace std;
void Game::Draw(Color col)
{
  grid.Draw(col);
}

void Game::updateCell(int row, int column, int value)
{
  grid.updateCell(row, column, value);
}

int Game::howManyNeighbors(int row, int column)
{
  int count = 0;
  // Use this vector of pairs to represent neighbor shifts
  vector<pair<int, int>> shifts = {
      // Horizonal sides
      {1, 0},
      {-1, 0},

      // Vertical sides
      {0, 1},
      {0, -1},

      // diagonals
      {1, 1},
      {-1, -1},
      {1, -1},
      {-1, 1}};
  // Check neighbors
  for (const auto &shift : shifts)
  {
    // Define coords modulo size so neighbors wrap around bounds
    int shiftedRow = (row + shift.first) % grid.TotalRows();
    int shiftedColoumn = (column + shift.second) % grid.TotalColumns();
    count += grid.getValue(shiftedRow, shiftedColoumn);
  }
  return count;
}

void Game::updateGame()
{
  if (isRunning())
  { // go through all cells
    for (int row = 0; row < grid.TotalRows(); row++)
    {
      for (int col = 0; col < grid.TotalColumns(); col++)
      {
        int liveNeighbors = howManyNeighbors(row, col);
        int cellState = grid.getValue(row, col);

        // Update cells to temp
        if (cellState == 1)
        {
          if (liveNeighbors > 3 || liveNeighbors < 2)
          // Overpopulation and Underpopulation:
          {
            temp.updateCell(row, col, 0);
          }
          else
          {
            temp.updateCell(row, col, 1);
          }
        }
        else
        {
          if (liveNeighbors == 3)
          {
            // Reproduction
            temp.updateCell(row, col, 1);
          }
          else
          {
            temp.updateCell(row, col, 0);
          }
        }
      }
    }
    grid = temp;
  }
}

bool Game::isRunning()
{
  return run;
}

void Game::change(int row, int col, bool left)
{
  if (left)
  {
    grid.updateCell(row, col, 1);
  }
  else
  {
    grid.updateCell(row, col, 0);
  }
}

void Game::RandomState()
{
  if (!isRunning())
  {
    grid.randomFill();
  }
}
