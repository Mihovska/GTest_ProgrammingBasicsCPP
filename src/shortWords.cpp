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
#include <set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::string input;
  std::getline(cin, input);

  std::transform(input.begin(), input.end(), input.begin(), ::tolower);

  std::set<std::string> shortWords;

  std::istringstream iss(input);
  std::string word;

  while (iss >> word) {
    if (word.size() < 5) {
      shortWords.insert(word);
    }
  }

  std::vector<std::string> sortedWords(shortWords.begin(), shortWords.end());

  std::sort(sortedWords.begin(), sortedWords.end());

  for (size_t i = 0; i < sortedWords.size(); ++i) {
    if (i > 0) {
      cout << ", ";
    }
    cout << sortedWords[i];
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
