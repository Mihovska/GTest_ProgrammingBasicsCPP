#ifndef __JOIN_H__
#define __JOIN_H__

#include <string>
#include <vector>
#include <sstream>

template<typename T>
std::string join(const std::vector<T>& elements, const std::string& joinStr) {
  std::ostringstream joinedString;

  if (elements.empty()) {
    return "";
  }

  for (size_t i = 0; i < elements.size(); ++i) {
    joinedString << elements[i];
    if (i != elements.size() - 1) {
      joinedString << joinStr;
    }
  }
  return joinedString.str();
}

#endif  // __JOIN_H__
