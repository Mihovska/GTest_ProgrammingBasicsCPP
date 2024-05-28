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
  std::queue<std::string> names;
  std::string input;

  while (cin >> input && input != "End") {
    if (input == "Paid") {
      while (!names.empty()) {
        cout << names.front() << std::endl;
        names.pop();
      }
    } else {
      names.push(input);
    }
  }
  cout << names.size() << " people remaining." << std::endl;
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
