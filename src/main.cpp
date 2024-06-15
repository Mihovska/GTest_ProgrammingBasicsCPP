#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cstddef>
#include <map>


#ifdef TESTING
#include <gtest/gtest.h>
#endif


int process(std::istream &cin, std::ostream &cout) {
  std::string textLine;
  std::getline(cin, textLine);

  for (char &c : textLine) {
    if (!isalpha(c)) {
      c = ' ';
    }
  }
  std::set<std::string> uniqueWords;

  std::istringstream iss(textLine);

  while (iss >> textLine) {
    uniqueWords.insert(textLine);
  }

  char letter;
  while (cin >> letter && letter != '.') {
    letter = tolower(letter);
    bool bFound = false;

    for (const std::string &currWord : uniqueWords) {
      std::string transformed = currWord;
      std::transform(transformed.begin(), transformed.end(), transformed.begin(), ::tolower);

      if (transformed.find(letter) != std::string::npos) {
        bFound = true;
        cout << currWord << " ";
      }
    }

    if (!bFound) {
      cout << "---";
    }

    cout << std::endl;
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
