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

void findMinMaxAtIndices(const int arr[], int size,
                         const std::function<bool(int)> &evenIndexFilter,
                         const std::function<bool(int)> &oddIndexFilter,
                         std::ostream &cout) {
  int minEven = INT_MAX;
  int maxOdd = INT_MIN;

  for (int i = 0; i < size; ++i) {
    int num = arr[i];
    if (evenIndexFilter(i)) {
      minEven = std::min(minEven, num);
    }
    if (oddIndexFilter(i)) {
      maxOdd = std::max(maxOdd, num);
    }
  }

  cout << std::fixed << std::setprecision(2);
  cout << static_cast<double>(maxOdd) << " " << static_cast<double>(minEven);
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

  auto evenIndexFilter = [](int index) { return index % 2 == 0; };
  auto oddIndexFilter = [](int index) { return index % 2 == 1; };

  double averageNumber = findAverage(arr, size);

  findMinMaxAtIndices(arr, size, evenIndexFilter, oddIndexFilter, cout);

  cout << std::fixed << std::setprecision(2);
  cout << " " << averageNumber << std::endl;

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
