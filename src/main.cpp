#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cstddef>
#include <map>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

const int SIZE = 10;
const char HEALTHY = '.';
const char RUSTY = '!';

void spreadRust(std::vector<std::vector<char>> &matrix) {
  std::vector<std::vector<char>> newMatrix = matrix;

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      if (matrix[i][j] == RUSTY) {
        if (i > 0 && matrix[i - 1][j] == HEALTHY) {
          newMatrix[i - 1][j] = RUSTY;
        }
        if (i < SIZE - 1 && matrix[i + 1][j] == HEALTHY) {
          newMatrix[i + 1][j] = RUSTY;
        }
        if (j > 0 && matrix[i][j - 1] == HEALTHY) {
          newMatrix[i][j - 1] = RUSTY;
        }
        if (j < SIZE - 1 && matrix[i][j + 1] == HEALTHY) {
          newMatrix[i][j + 1] = RUSTY;
        }
      }
    }
  }
  matrix = newMatrix;
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::vector<char>> matrix(SIZE, std::vector<char>(SIZE));
  int timeUnits;

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      cin >> matrix[i][j];
    }
  }

  cin >> timeUnits;

  for (int t = 0; t < timeUnits; ++t) {
    spreadRust(matrix);
  }

  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      cout << matrix[i][j];
    }
    cout << std::endl;
  }

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
