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
#include <list>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class Shifter {
 public:
  std::list<std::string> words;

  Shifter() = default;

  void readInput(std::istream &cin) {
    std::string line;
    std::getline(cin, line);
    std::istringstream iss(line);
    std::string word;

    while (iss >> word) {
      words.push_back(word);
    }
  }

  void shift(int shiftBy) {
    for (int i = 0; i < shiftBy; ++i) {
      std::string shiftedWord = words.back();
      words.pop_back();
      words.push_front(shiftedWord);
    }
  }

  void printOutput(std::ostream &cout) const {
    for (const auto &word : words) {
      cout << word << std::endl;
    }
  }
};

int process(std::istream &cin, std::ostream &cout) {
  Shifter shifter;
  shifter.readInput(cin);

  int shiftNumber;
  cin >> shiftNumber;

  shifter.shift(shiftNumber);
  shifter.printOutput(cout);

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
