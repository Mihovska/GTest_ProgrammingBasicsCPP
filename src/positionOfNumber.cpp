#include <algorithm>
#include <array>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef TESTING
#include <gtest/gtest.h>
#endif


int process(std::istream &cin, std::ostream &cout) {
  int rows;
  int cols;
  int number;

  cin >> rows >> cols;

  std::vector<std::vector<int>> matrix(rows, std::vector<int> (cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cin >> matrix[i][j];
    }
  }

  cin >> number;

  bool found = false;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (matrix[i][j] == number) {
        cout << i << " " << j << std::endl;
        found = true;
      }
    }
  }

  if (!found) {
    cout << "not found" << std::endl;
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
