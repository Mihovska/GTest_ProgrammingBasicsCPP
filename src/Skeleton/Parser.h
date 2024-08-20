#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <iostream>
#include <sstream>

template <typename T>
class Parser {
  std::istream &in;
  const std::string &stopLine;

 public:
  Parser(std::istream& in, const std::string& stopLine) :
    in(in), stopLine(stopLine) {}

  bool readNext(T& value) {
  if (in.eof()) {
    return false;
  }
  std::string line;
  std::getline(in, line);

  if (line == stopLine) {
    return false;
  }

  std::istringstream iss(line);
  iss >> value;
  return true;
  }
};

#endif  // !PARSER_H
