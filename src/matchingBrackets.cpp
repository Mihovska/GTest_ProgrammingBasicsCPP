#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <string>
#include <stack>
#include <iostream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

std::string printSubExpression(std::string::const_iterator start,
                               std::string::const_iterator end) {
  std::string subExpression;
  for (auto it = start; it != end + 1; ++it) {
    subExpression += *it;
  }
  return subExpression;
}

std::string findSubExpression(const std::string &expression) {
  std::stack<std::string::const_iterator> brackets;
  std::string subExp;

  for (auto it = expression.begin(); it != expression.end(); ++it) {
    switch (*it) {
      case '(':
        brackets.push(it);
        break;
      case ')':
        if (!brackets.empty()) {
          auto start = brackets.top();
          brackets.pop();
          subExp += printSubExpression(start, it);
          subExp += '\n';
        }
        break;
      default:
        break;
    }
  }
  return subExp;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string expression;
  std::getline(cin, expression);

  std::string result = findSubExpression(expression);
  cout << result;
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
