#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int findMaxNumber(int arr[], int size) {
  int maxNum = INT_MIN;

  for (int i = 0; i < size; ++i) {
    if (i % 2 == 1 && arr[i] > maxNum) {
      maxNum = arr[i];
    }
  }
  return maxNum;
}

int findMinNumber(int arr[], int size) {
  int minNum = INT_MAX;

  for (int i = 0; i < size; ++i) {
    if (i % 2 == 0 && arr[i] < minNum) {
      minNum = arr[i];
    }
  }
  return minNum;
}

double findAverage(int arr[], int size) {
  int sum = 0;

  for (int i = 0; i < size; ++i) {
    sum += arr[i];
  }

  return sum * 1.0 / size;
}

int process(std::istream &cin, std::ostream &cout) {
  int size = 0;
  cin >> size;

  int *arr = new int[size];

  for (int i = 0; i < size; ++i) {
    cin >> arr[i];
  }

  double maxNumberOddPositions = findMaxNumber(arr, size);
  double minNumberEvenPositions = findMinNumber(arr, size);
  double averageNumber = findAverage(arr, size);

  cout << std::fixed << std::setprecision(2);
  cout << maxNumberOddPositions << " " << minNumberEvenPositions << " "
       << averageNumber << std::endl;

  for (int i = size - 1; i >= 0; --i) {
    cout << arr[i] << " ";
  }
  cout << std::endl;

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
