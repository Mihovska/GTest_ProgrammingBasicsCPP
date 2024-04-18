#include <algorithm>
#include <array>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string printComparissonSign(std::vector<std::string> firstVec,
                                 std::vector<std::string> secondVec, int size) {
  std::string result;
  for (int i = 0; i < size; ++i) {
    if (i < firstVec.size() && i < secondVec.size()) {
      std::string firstNum = firstVec[i];
      std::string secondNum = secondVec[i];

      if (firstNum.length() > secondNum.length()) {
        result += "<";
      } else if (firstNum.length() < secondNum.length()) {
        result += ">";
      } else {
        if (firstNum > secondNum) {
          result += "<";
        } else if (firstNum < secondNum) {
          result += ">";
        } else {
          result += "=";
        }
      }
    } else if (i < firstVec.size()) {
      result += "+";
    } else {
      result += "-";
    }
  }
  return result;
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::string> firstVector;
  std::vector<std::string> secondVector;

  std::string line;

  getline(cin, line);
  std::istringstream issFirst(line);
  std::string num;
  while (issFirst >> num) {
    firstVector.push_back(num);
  }

  getline(cin, line);
  std::istringstream issSecond(line);
  while (issSecond >> num) {
    secondVector.push_back(num);
  }

  std::string result;
  if (firstVector.size() < secondVector.size()) {
    result =
        printComparissonSign(firstVector, secondVector, secondVector.size());
  } else if (firstVector.size() > secondVector.size()) {
    result =
        printComparissonSign(firstVector, secondVector, firstVector.size());
  } else {
    result =
        printComparissonSign(firstVector, secondVector, firstVector.size());
  }

  cout << result << std::endl;

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
