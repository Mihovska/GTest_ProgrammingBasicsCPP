#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>
std::string operator+(std::string str, int num) {
  std::stringstream ss;
  ss << num;

  return str + ss.str();
}

std::vector<std::string> &operator<<(std::vector<std::string> &formattedLines, std::string line) {
  formattedLines.push_back(line);

  return formattedLines;
}

std::ostream &operator<<(std::ostream &cout, std::vector<std::string> &formattedLines) {
  for (std::string line : formattedLines) {
    cout << line << std::endl;
  }
  return cout;
}

#endif // !OPERATORS_H
