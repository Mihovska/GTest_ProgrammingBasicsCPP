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

bool compareMatrices(const std::vector<std::vector<int>> &matrix1,
                     const std::vector<std::vector<int>> &matrix2) {
  if (matrix1.size() != matrix2.size()) {
    return false;
  }

  for (size_t i = 0; i < matrix1.size(); ++i) {
    if (matrix1[i].size() != matrix2[i].size()) {
      return false;
    }

    for (size_t j = 0; j < matrix2[i].size(); ++j) {
      if (matrix1[i][j] != matrix2[i][j]) {
        return false;
      }
    }
  }
  return true;
}

std::vector<std::vector<int>> readMatrix(std::istream &cin) {
  int rows;

  cin >> rows;
  cin.ignore();
  std::vector<std::vector<int>> matrix;

  matrix.resize(rows);
  for (int i = 0; i < rows; ++i) {
    std::string line;
    std::getline(cin, line);
    std::istringstream iss(line);

    int num;
    while (iss >> num) {
      matrix[i].push_back(num);
    }
  }

  return matrix;
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::vector<int>> matrix1 = readMatrix(cin);
  std::vector<std::vector<int>> matrix2 = readMatrix(cin);

  if (compareMatrices(matrix1, matrix2)) {
    cout << "equal" << std::endl;
  } else {
    cout << "not equal" << std::endl;
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
