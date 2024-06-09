#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string earliestLexicographicallyStr(const std::vector<std::string> &words) {
  std::string earliest;
  for (auto word : words) {
    if (earliest.empty() || word < earliest) {
      earliest = word;
    }
  }
  return earliest;
}

std::string shortestStr(const std::vector<std::string> &words) {
  std::string shortest;
  for (auto word : words) {
    if (shortest.empty() || word.size() < shortest.size()) {
      shortest = word;
    }
  }
  return shortest;
}

std::string longestStr(const std::vector<std::string> &words) {
  std::string longest;
  for (auto word : words) {
    if (longest.empty() || word.size() > longest.size()) {
      longest = word;
    }
  }
  return longest;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string inputWords;
  std::getline(cin, inputWords);
  int number;
  cin >> number;

  std::vector<std::string> words;

  std::istringstream iss(inputWords);
  std::string word;

  while (iss >> word) {
    words.push_back(word);
  }

  std::string (*func)(const std::vector<std::string> &);
  switch (number) {
    case 1:
      func = &earliestLexicographicallyStr;
      break;
    case 2:
      func = &shortestStr;
      break;
    case 3:
      func = &longestStr;
      break;
  }

  cout << func(words) << std::endl;
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
