#include "TryParse.h"
#include <sstream>

bool tryParse(const std::string& aString, int& a) {
  std::istringstream iss(aString);
  iss >> a;
  return !iss.fail() && iss.eof();
}
