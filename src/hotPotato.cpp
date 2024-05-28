#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <queue>
#include <iostream>
#include <sstream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif


void printResult(std::queue<std::string> &names, int toss, std::ostream &cout) {
  while (names.size() > 1) {
    for (int i = 1; i < toss; ++i) {
      names.push(names.front());
      names.pop();
    }
    cout << "Removed " << names.front() << std::endl;
    names.pop();
  }
  cout << "Last is " << names.front() << std::endl;
}

int process(std::istream &cin, std::ostream &cout) {
  std::queue<std::string> names;
  std::string input;
  int toss = 0;

  std::getline(cin, input);
  std::istringstream iss(input);

  std::string name;
  while (iss >> name) {
    names.push(name);
  }

  cin >> toss;

  printResult(names, toss, cout);
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
