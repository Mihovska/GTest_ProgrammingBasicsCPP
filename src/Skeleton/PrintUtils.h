#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>& vec) {
  for (const auto& element : vec) {
    std::cout << element << " ";
  }
  std::cout << std::endl;
}

#endif  // !PRINTUTILS_H
