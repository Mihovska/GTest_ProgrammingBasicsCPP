#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::string input;
  std::getline(cin, input);

  std::multiset<int> numbers;

  std::istringstream iss(input);
  int number;

  while (iss >> number) {
    numbers.insert(number);
  }

  for (auto it = numbers.begin(); it != numbers.end(); ++it) {
    if (it != numbers.begin()) {
      cout << " <= ";
    }
    cout << *it;
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
