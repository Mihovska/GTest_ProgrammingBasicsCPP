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
  std::vector<std::string> firstVector;
  std::vector<std::string> secondVector;

  std::string line;

  getline(cin, line);
  std::istringstream issFirst(line);
  std::string num;
  while (issFirst >> num) {
    firstVector.push_back(num);
  }

  getline(cin, line);
  std::istringstream issSecond(line);
  while (issSecond >> num) {
    secondVector.push_back(num);
  }

  std::string output;
  int size = std::min(firstVector.size(), secondVector.size());

  for (int i = 0; i < size; ++i) {
    if (firstVector[i] < secondVector[i]) {
      cout << ">";
    } else if (firstVector[i] > secondVector[i]) {
      cout << "<";
    } else {
      cout << "=";
    }
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
