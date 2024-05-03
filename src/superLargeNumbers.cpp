#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string printComparissonSign(std::vector<std::string> &firstVec,
                                 std::vector<std::string> &secondVec) {
  std::ostringstream resultStream;

  auto firstIt = firstVec.begin();
  auto secondIt = secondVec.begin();

  while (firstIt != firstVec.end() && secondIt != secondVec.end()) {
    const std::string firstVecString = *firstIt;
    const std::string secondVecString = *secondIt;

    bool isStringEqual = firstVecString == secondVecString;
    bool firstStringIsLonger = firstVecString.size() > secondVecString.size();
    bool firstStringIsShorter = firstVecString.size() < secondVecString.size();
    bool firstStringIsGreater = firstVecString > secondVecString;
    bool firstStringIsSmaller = firstVecString < secondVecString;

    if (isStringEqual) {
      resultStream << '=';
    } else if (firstStringIsShorter ||
               (firstStringIsSmaller && !firstStringIsLonger)) {
      resultStream << '>';
    } else if (firstStringIsLonger ||
               (firstStringIsGreater && !firstStringIsShorter)) {
      resultStream << '<';
    }

    ++firstIt;
    ++secondIt;
  }

  while (firstIt != firstVec.end()) {
    resultStream << '+';
    ++firstIt;
  }
  while (secondIt != secondVec.end()) {
    resultStream << '-';
    ++secondIt;
  }

  return resultStream.str();
}

std::vector<std::string> getVector(std::istream &cin, std::string &line) {
  std::getline(cin, line);
  std::istringstream iss(line);
  std::string num;

  std::vector<std::string> result;
  while (iss >> num) {
    result.push_back(num);
  }
  return result;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string line;
  std::vector<std::string> firstVector = getVector(cin, line);
  std::vector<std::string> secondVector = getVector(cin, line);

  std::string result = printComparissonSign(firstVector, secondVector);

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
