#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>

std::vector<std::string> operator+(const std::vector<std::string> &vec1, const std::vector<std::string> &vec2) {
  std::vector<std::string> resultVector;

  for (int i = 0; i < vec1.size(); ++i) {
    resultVector.push_back(vec1[i] + " " + vec2[i]);
  }

  return resultVector;
}

#endif // !SUMOFVECTORS_H
