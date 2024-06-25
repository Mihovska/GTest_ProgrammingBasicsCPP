#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <vector>
#include <set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

bool isSquare(int num) {
  if (num < 0) {
    return false;
  }

  auto root = static_cast<int>(std::sqrt(num));

  return (root * root == num);
}

int process(std::istream &cin, std::ostream &cout) {
  std::multiset<int> squares;
  int num;

  while (cin >> num) {
    if (isSquare(num)) {
      squares.insert(num);
    }
  }

  std::vector<int> sortedSquares(squares.begin(), squares.end());
  std::sort(sortedSquares.rbegin(), sortedSquares.rend());

  for (const int &square : sortedSquares) {
    cout << square << " ";
  }

  cout << std::endl;
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
