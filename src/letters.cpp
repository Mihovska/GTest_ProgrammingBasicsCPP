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
#include <set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class TextProcessor {
 public:
  void readText(std::istream &input) {
    std::getline(input, textLine);

    for (char &c : textLine) {
      if (!isalpha(c)) {
        c = ' ';
      }
    }

    std::istringstream iss(textLine);
    std::string word;
    while (iss >> word) {
      uniqueWords.insert(word);
    }
  }

  void processLetters(std::istream &input, std::ostream &output) {
    char letter;
    while (input >> letter && letter != '.') {
      letter = tolower(letter);
      bool bFound = false;

      for (const std::string &currWord : uniqueWords) {
          std::string transformed = currWord;
          std::transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);

        if (transformed.find(letter) != std::string::npos) {
          bFound = true;

          output << currWord << " ";
        }
      }
      if (!bFound) {
        output << "---";
      }
      output << std::endl;
    }
  }

 private:
  std::string textLine;
  std::set<std::string> uniqueWords;
};

int process(std::istream &cin, std::ostream &cout) {
  TextProcessor processor;
  processor.readText(cin);

  processor.processLetters(cin, cout);

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
