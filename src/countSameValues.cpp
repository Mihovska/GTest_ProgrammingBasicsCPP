#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <map>
#include <iostream>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::map<double, int> valuesCount;
  std::vector<double> valuesOrder;

  double value;
  while (cin >> value) {
    if (valuesCount.find(value) == valuesCount.end()) {
      valuesOrder.push_back(value);
    }
    valuesCount[value]++;
  }

  for (const auto &number : valuesOrder) {
    cout << number << " - " << valuesCount[number] << " times" << std::endl;
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
