#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>

#ifdef TESTING
#include <gtest/gtest.h>
#endif


const int SIZE = 10;
const char HEALTHY = '.';
const char RUSTY = '!';

class Cell {
 public:
  char state;

  Cell(char initialState = HEALTHY) : state(initialState) {}

  bool isHealthy() const {
    return state == HEALTHY;
  }

  bool isRusty() const {
    return state == RUSTY;
  }

  void setRusty() {
    state = RUSTY;
  }
};

class Matrix {
 private:
  std::vector<std::vector<Cell>> cells;

 public:
  Matrix() : cells(SIZE, std::vector<Cell>(SIZE)) {}

  void initialize(std::istream &cin) {
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        char input;
        cin >> input;
        cells[i][j] = Cell(input);
      }
    }
  }

  Cell& at(int i, int j) {
    return cells[i][j];
  }

  void spreadRust() {
    std::vector<std::vector<Cell>> newCells = cells;

    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        if (cells[i][j].isRusty()) {
          if (i > 0 && cells[i - 1][j].isHealthy()) {
            newCells[i - 1][j].setRusty();
          }
          if (i < SIZE - 1 && cells[i + 1][j].isHealthy()) {
            newCells[i + 1][j].setRusty();
          }
          if (j > 0 && cells[i][j - 1].isHealthy()) {
            newCells[i][j - 1].setRusty();
          }
          if (j < SIZE - 1 && cells[i][j + 1].isHealthy()) {
            newCells[i][j + 1].setRusty();
          }
        }
      }
    }
    cells = newCells;
  }

  void print(std::ostream &cout) {
    for (int i = 0; i < SIZE; ++i) {
      for (int j = 0; j < SIZE; ++j) {
        cout << cells[i][j].state;
      }
      cout << std::endl;
    }
  }
};


class Rusty {
 private:
  Matrix matrix;

 public:
  Rusty(std::istream &cin) {
    matrix.initialize(cin);
  }

  void spreadRustByUnits(int units) {
    for (int i = 0; i < units; ++i) {
      matrix.spreadRust();
    }
  }

  void printMatrix(std::ostream &cout) {
    matrix.print(cout);
  }
};

int process(std::istream &cin, std::ostream &cout) {
  Rusty rusty(cin);

  int timeUnits;
  cin >> timeUnits;
  rusty.spreadRustByUnits(timeUnits);
  rusty.printMatrix(cout);

  return 0;
}

int main(int argc, char **argv) {
#ifdef TESTING
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  process(std::cin, std::cout);
  return 0;
#endif
}
