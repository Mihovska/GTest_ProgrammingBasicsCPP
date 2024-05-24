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

int calculateSum(std::stack<int> numbers) {
  int sum = 0;
  while (!numbers.empty()) {
    sum += numbers.top();
    numbers.pop();
  }
  return sum;
}

void addNumbers(std::stack<int> &numbers, int number1, int number2) {
  numbers.push(number1);
  numbers.push(number2);
}

void removeNumbers(std::stack<int> &numbers, int count) {
  if (count <= numbers.size()) {
    for (int i = 0; i < count; i++) {
      numbers.pop();
    }
  }
}

int process(std::istream &cin, std::ostream &cout) {
  std::stack<int> numbers;
  std::string input;

  std::getline(cin, input);
  std::istringstream iss(input);
  int number = 0;

  while (iss >> number) {
    numbers.push(number);
  }

  while (std::getline(cin, input)) {
    if (input == "end") {
      break;
    }
    std::istringstream commandStream(input);
    std::string command;
    commandStream >> command;

    if (command == "add") {
      int number1 = 0;
      int number2 = 0;

      commandStream >> number1 >> number2;
      addNumbers(numbers, number1, number2);
    } else if (command == "remove") {
      int count = 0;
      commandStream >> count;
      removeNumbers(numbers, count);
    }
  }

  int sum = calculateSum(numbers);
  cout << sum << std::endl;

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
