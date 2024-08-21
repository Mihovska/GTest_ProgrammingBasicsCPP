#ifndef __SPLIT_H__
#define __SPLIT_H__

#include <vector>
#include <string>
#include <sstream>

template <typename T>
std::vector<T> split(const std::string& line, char separator) {
  std::vector<T> result;
  std::istringstream iss(line);

  std::string token;
  while (std::getline(iss, token, separator)) {
    T value;
    std::istringstream tokenStream(token);
    tokenStream >> value;

    result.push_back(value);
  }

  return result;
}

#endif  // __SPLIT_H__
