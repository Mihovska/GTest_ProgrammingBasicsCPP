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
#include <stack>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string reverseString(const std::string &input) {
  std::stack<std::string> words;
  std::istringstream iss(input);
  std::string word;

  while (iss >> word) {
    std::stack<char> reversedChars;
    for (char ch : word) {
      reversedChars.push(ch);
    }
    std::string reversedWord;
    while (!reversedChars.empty()) {
      reversedWord += reversedChars.top();
      reversedChars.pop();
    }
    words.push(reversedWord);
  }

  std::string reversedString;
  while (!words.empty()) {
     reversedString += words.top();
    words.pop();
    if (!words.empty()) {
      reversedString += " ";
    }
  }
  return reversedString;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string input;
  std::getline(cin, input);

  std::string reversedString = reverseString(input);
  cout << reversedString << std::endl;
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
