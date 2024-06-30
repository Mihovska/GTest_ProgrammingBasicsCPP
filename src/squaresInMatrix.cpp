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


int process(std::istream &cin, std::ostream &cout) {
  int rows;
  int cols;

  cin >> rows >> cols;

  std::vector<std::vector<char>> matrix(rows, std::vector<char> (cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }

  int count = 0;

  for (int i = 0; i < rows - 1; ++i) {
    for (int j = 0; j < cols - 1; ++j) {

    if (matrix[i][j] == matrix[i + 1][j] &&
        matrix[i][j] == matrix[i][j + 1] &&
        matrix[i][j] == matrix[i + 1][j + 1]) {
        count++;
      }
    }
  }

  cout << count << std::endl;

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
