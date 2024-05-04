#include <algorithm>
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

double findMinMaxAtIndices(const int arr[], int size,
                           const std::function<bool(int)> &positionPredicate,
                           const std::function<int(int, int)> &compareNums,
                           int minMaxLimit) {
  int result = minMaxLimit;

  for (int i = 0; i < size; ++i) {
    int num = arr[i];
    if (positionPredicate(i)) {
      result = compareNums(result, num);
    }
  }

  return result;
}

double findAverage(const int arr[], int size) {
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

  auto isEvenIndex = [](int index) { return index % 2 == 0; };
  auto isOddIndex = [](int index) { return index % 2 == 1; };

  auto minElemLambda = [](int a, int b) { return std::min(a, b); };
  auto maxElemLambda = [](int a, int b) { return std::max(a, b); };

  double minEven =
      findMinMaxAtIndices(arr, size, isEvenIndex, minElemLambda, INT_MAX);
  double maxOdd =
      findMinMaxAtIndices(arr, size, isOddIndex, maxElemLambda, INT_MIN);

  double averageNumber = findAverage(arr, size);

  cout << std::fixed << std::setprecision(2);
  cout << maxOdd << " " << minEven << " " << averageNumber << std::endl;

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
