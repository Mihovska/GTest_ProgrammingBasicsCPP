#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <iostream>
#include <cstring>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  int rows;
  int cols;
  int firstRows;
  int firstCols;

  cin >> rows >> cols;

  int **twoDArray = new int *[rows];
  for (int i = 0; i < rows; ++i) {
    twoDArray[i] = new int[cols];
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> twoDArray[i][j];
    }
  }

  cin >> firstRows >> firstCols;

  for (int i = 0; i < firstRows && i < rows; ++i) {
    for (int j = 0; j < firstCols && j < cols; ++j) {
      cout << twoDArray[i][j] << " ";
    }
    cout << std::endl;
  }

  for (int i = 0; i < rows; ++i) {
    delete[] twoDArray[i];
  }
  delete[] twoDArray;

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
