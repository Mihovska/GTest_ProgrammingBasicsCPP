#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  int linesCount = 0;
  cin >> linesCount;
  std::map<std::string, std::map<std::string, std::vector<std::string>>> data;

  for (int i = 0; i < linesCount; ++i) {
    std::string continent;
    std::string country;
    std::string city;

    cin >> continent >> country >> city;

    data[continent][country].push_back(city);
  }

  for (auto &continent : data) {
    for (auto &country : continent.second) {
      std::sort(country.second.begin(), country.second.end());
    }
  }

  for (const auto &continent : data) {
    cout << continent.first << ":" << std::endl;
    for (const auto &country : continent.second) {
      cout << "  " << country.first << " -> ";
      for (size_t i = 0; i < country.second.size(); ++i) {
        if (i > 0) {
          cout << ", ";
        }
        cout << country.second[i];
      }
      cout << std::endl;
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
