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

void pushElement(std::stack<int> &numbers, int element) {
  numbers.push(element);
}

void popElement(std::stack<int> &numbers) {
  numbers.pop();
}

int findMaxElement(std::stack<int> &numbers) {
  int maxElement = INT_MIN;
  std::stack<int> temp;

  while (!numbers.empty()) {
    int current = numbers.top();
    numbers.pop();
    if (current > maxElement) {
      maxElement = current;
    }
    temp.push(current);
  }
  while (!temp.empty()) {
    numbers.push(temp.top());
    temp.pop();
  }
  return maxElement;
}



int findMinElement(std::stack<int> &numbers) {
  int minElement = INT_MAX;
  std::stack<int> temp;

  while (!numbers.empty()) {
    int current = numbers.top();
    numbers.pop();
    if (current < minElement) {
      minElement = current;
    }
    temp.push(current);
  }
  while (!temp.empty()) {
    numbers.push(temp.top());
    temp.pop();
  }
  return minElement;
}

void printStackReverse(const std::stack<int> &numbers, std::ostream &cout) {
  std::stack<int> temp = numbers;

  bool bFirst = true;
  while (!temp.empty()) {
    if (bFirst) {
        bFirst = false;
    } else {
      cout << ", ";
    }
    cout << temp.top();
    temp.pop();
  }
  cout << std::endl;
}

void processElements(int N, std::istream &cin, std::ostream &cout) {
  std::stack<int> numbers;

  for (int i = 0; i < N; ++i) {
    int type = 0;
    cin >> type;
    int element = 0;

    switch (type) {
      case 1:
       cin >> element;
       pushElement(numbers, element);
       break;
      case 2:
       popElement(numbers);
       break;
      case 3:
       cout << findMaxElement(numbers) << std::endl;
      break;
      case 4:
       cout << findMinElement(numbers) << std::endl;
    }
  }
  printStackReverse(numbers, cout);
}

int process(std::istream &cin, std::ostream &cout) {
  int N = 0;
  cin >> N;

  processElements(N, cin, cout);

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
