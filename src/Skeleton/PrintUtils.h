#ifndef _PRINTUTILS_H_
#define _PRINTUTILS_H_

#include <iostream>

template <typename Container, typename Iterator>
void printContainer(Iterator begin, Iterator end) {
  while (begin != end) {
    std::cout << *begin;
    ++begin;
    if (begin != end) {
      std::cout << " ";
    }
  }
  std::cout << std::endl;
}

#endif  // _PRINTUTILS_H_
