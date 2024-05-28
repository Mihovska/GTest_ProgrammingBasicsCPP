#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <queue>
#include <iostream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif


int process(std::istream &cin, std::ostream &cout) {
  std::queue<int> numbers;
  int input;

  while (cin >> input) {
    numbers.push(input);
  }

  bool bFirst = true;
  while (!numbers.empty()) {
    int current = numbers.front();
    numbers.pop();

    if (current % 2 == 0) {
      if (bFirst) {
        bFirst = false;
      } else {
        cout << ", ";
      }
      cout << current;
    }
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
