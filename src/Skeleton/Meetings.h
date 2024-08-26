#ifndef MEETINGS_H
#define MEETINGS_H

#include <iostream>
#include <string>

class Meeting {
  size_t inputOrder;
  std::string id;

 public:
  Meeting(size_t inputOrder, std::istream& in) : inputOrder(inputOrder);
};

#endif  // MEETINGS_H
