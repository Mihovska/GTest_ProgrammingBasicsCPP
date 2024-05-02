#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string printComparissonSign(std::vector<std::string> firstVec,
                                 std::vector<std::string> secondVec) {
  std::string result;

  auto firstIt = firstVec.begin();
  auto secondIt = secondVec.begin();

  while (firstIt != firstVec.end() && secondIt != secondVec.end()) {
    const std::string first = *firstIt;
    const std::string second = *secondIt;

    if (first.size() != second.size()) {
      result += first.size() > second.size() ? "<" : ">";
    } else {
      if (first == second) {
        result += "=";
      } else {
        result += first > second ? "<" : ">";
      }
    }
    ++firstIt;
    ++secondIt;
  }

  while (firstIt != firstVec.end()) {
    result += "+";
    ++firstIt;
  }
  while (secondIt != secondVec.end()) {
    result += "-";
    ++secondIt;
  }

  return result;
}

std::vector<std::string> getVector(std::istream &cin, std::string line) {
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
