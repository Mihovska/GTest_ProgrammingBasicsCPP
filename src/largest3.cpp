#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>
#include <set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::set<double> numbers;

  double number;

  while (cin >> number) {
    numbers.insert(number);

    if (numbers.size() > 3) {
      numbers.erase(numbers.begin());
    }
  }

  for (auto it = numbers.rbegin(); it != numbers.rend(); ++it) {
    cout << *it << " ";
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
