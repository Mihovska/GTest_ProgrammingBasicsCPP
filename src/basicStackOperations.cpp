#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <stack>
#include <iostream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void pushElements(std::stack<int> &numbers, int N, std::istream &cin) {
  for (int i = 0; i < N; ++i) {
    int number = 0;
    cin >> number;
    numbers.push(number);
  }
}

void popElements(std::stack<int> &numbers, int count) {
  while (count-- > 0 && !numbers.empty()) {
    numbers.pop();
  }
}

bool containsElement(const std::stack<int> &numbers, int element) {
  std::stack<int> tempNumbers = numbers;
  while (!tempNumbers.empty()) {
     if (tempNumbers.top() == element) {
      return true;
    }
    tempNumbers.pop();
  }
  return false;
}

int findSmallestElement(const std::stack<int> &numbers) {
  if (numbers.empty()) {
    return 0;
  }
  std::stack<int> tempNumbers = numbers;
  int minElement = INT_MAX;
  while (!tempNumbers.empty()) {
    if (tempNumbers.top() < minElement) {
      minElement = tempNumbers.top();
    }
    tempNumbers.pop();
  }
  return minElement;
}

int process(std::istream &cin, std::ostream &cout) {
  int N = 0;
  int S = 0;
  int X = 0;

  cin >> N >> S >> X;

  std::stack<int> numbers;

  pushElements(numbers, N, cin);
  popElements(numbers, S);

  if (containsElement(numbers, X)) {
    cout << "true" << std::endl;
  } else {
    cout << findSmallestElement(numbers) << std::endl;
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
