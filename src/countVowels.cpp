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

int process(std::istream &cin, std::ostream &cout) {
  int size = 0;
  cin >> size;

  char *arr = new char[size];

  for (int i = 0; i < size; ++i) {
    cin >> arr[i];
  }

  int vowelCount = 0;
  int nonVowelCount = 0;

  auto isVowel = [&](char symbol) {
    switch (tolower(symbol)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
      return true;
    default:
      return false;
    }
  };

  auto isNonVowel = [&](char symbol) {
    return !isVowel(symbol) && std::isalpha(symbol);
  };

  for (int i = 0; i < size; ++i) {
    if (isVowel(arr[i])) {
      vowelCount++;
    } else if (isNonVowel(arr[i])) {
      nonVowelCount++;
    }
  }

  cout << vowelCount << " " << nonVowelCount << std::endl;

  delete[] arr;
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
