#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstddef>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::string inputLine;
  std::getline(cin, inputLine);

  size_t inputSize = inputLine.size();

  char *input = new char[inputSize + 1];
  std::copy(inputLine.begin(), inputLine.end(), input);
  input[inputSize] = '\0';

  char *lowerCaseOutput = new char[inputSize + 1];
  char *upperCaseOutput = new char[inputSize + 1];

  for (int i = 0; i < inputSize; ++i) {
    lowerCaseOutput[i] = std::tolower(input[i]);
    upperCaseOutput[i] = std::toupper(input[i]);
  }

  lowerCaseOutput[inputSize] = '\0';
  upperCaseOutput[inputSize] = '\0';

  cout << lowerCaseOutput << std::endl;
  cout << upperCaseOutput << std::endl;

  delete[] input;
  delete[] lowerCaseOutput;
  delete[] upperCaseOutput;

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
