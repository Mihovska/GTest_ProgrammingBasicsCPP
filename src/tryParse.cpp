#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <iostream>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

bool checkIfNumber(const char *str, int &number) {
  int temp = 0;

  while (*str != '\0') {
    if (isdigit(*str)) {
      temp *= 10;
      temp += *str - '0';
    } else {
      return false;
    }
    str++;
  }
  number = temp;
  return true;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string firstStr;
  std::string secondStr;
  cin >> firstStr >> secondStr;

  int firstInt = 0;
  int secondInt = 0;

  bool isFirstInt = checkIfNumber(firstStr.c_str(), firstInt);
  bool isSecondInt = checkIfNumber(secondStr.c_str(), secondInt);

  if (isFirstInt && isSecondInt) {
    cout << firstInt + secondInt << std::endl;
  } else {
    if (isFirstInt) {
      cout << firstInt << std::endl;
    } else {
      cout << "[error] " << firstStr << std::endl;
    }
    if (isSecondInt) {
      cout << secondInt << std::endl;
    } else {
      cout << "[error] " << secondStr << std::endl;
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
