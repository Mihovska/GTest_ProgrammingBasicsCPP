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

double calculateAverage(const std::list<int> &sizes) {
  if (sizes.empty())
    return 0.0;
  int sum = 0;
  for (int size : sizes) {
    sum += size;
  }
  return static_cast<double>(sum) / sizes.size();
}
int process(std::istream &cin, std::ostream &cout) {
  std::list<int> cows, sheep, other;
  std::string input;

  while (getline(cin, input)) {
    if (input.length() < 2) {
      continue;
    }

    char type = input[0];
    int size = input[1] - '0';

    switch (type) {
    case 'C':
      cows.push_back(size);
      break;
    case 'S':
      sheep.push_back(size);
      break;
    default:
      other.push_back(size);
    }
  }
  cout << cows.size() << "cows: "
       << ", Average size: " << std::fixed << std::setprecision(2)
       << calculateAverage(cows) << std::endl;
  cout << sheep.size() << "sheep: "
       << ", Average size: " << std::fixed << std::setprecision(2)
       << calculateAverage(sheep) << std::endl;
  cout << other.size() << "others: "
       << ", Average size: " << std::fixed << std::setprecision(2)
       << calculateAverage(other) << std::endl;

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
