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

int applyOperation(int a, int b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  default:
    return 0;
  }
}

void processNumber(std::istringstream &iss, std::stack<int> &numbers) {
  int currentNumber = 0;
  iss >> currentNumber;
  numbers.push(currentNumber);
}

void processOperator(char ch, std::stack<int> &numbers, std::stack<char> &operations) {
  while (!operations.empty() && (operations.top() == '+' || operations.top() == '-')) {
    char op = operations.top();
    operations.pop();
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();

    numbers.push(applyOperation(a, b, op));
  }
  operations.push(ch);
}

void applyRestOperations(std::stack<int> &numbers, std::stack<char> &operations) {
  while (!operations.empty()) {
    char op = operations.top();
    operations.pop();
    int b = numbers.top();
    numbers.pop();
    int a = numbers.top();
    numbers.pop();

    numbers.push(applyOperation(a, b, op));
  }
}

int evaluateExpression(const std::string &expression) {
  std::istringstream iss(expression);
  std::stack<int> numbers;
  std::stack<char> operations;
  char ch;

  while (iss >> ch) {
    if (std::isdigit(ch)) {
      iss.putback(ch);
      processNumber(iss, numbers);
    } else if (ch == '+' || ch == '-') {
      processOperator(ch, numbers, operations);
    }
  }

  applyRestOperations(numbers, operations);

  return numbers.top();
}


int process(std::istream &cin, std::ostream &cout) {
  std::string expression;
  std::getline(cin, expression);

  int result = evaluateExpression(expression);

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
