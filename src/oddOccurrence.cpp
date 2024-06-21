#include <algorithm>
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
#include <vector>
#include <unordered_map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string toLowerCase(const std::string &str) {
  std::string lowerStr = str;
  std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);

  return lowerStr;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string input;
  std::getline(cin, input);

  std::unordered_map<std::string, int> wordCount;
  std::vector<std::string> order;

  std::istringstream iss(input);
  std::string word;

  while (iss >> word) {
    std::string lowerWord = toLowerCase(word);

    if (wordCount.find(lowerWord) == wordCount.end()) {
      order.push_back(lowerWord);
    }
    wordCount[lowerWord] += 1;
  }

  bool first = true;
  for (const auto &w : order) {
    if (wordCount[w] % 2 != 0) {
      if (!first) {
        cout << ", ";
      }
      cout << w;
      first = false;
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
