#include "Article13Filter.h"

Article13Filter::Article13Filter(std::set<std::string> copyrighted) :
  copyrighted(copyrighted) {}

bool Article13Filter::blockIfCopyrighted(std::string s) {
  bool isBlocked = false;

  if (isCopyrighted(s)) {
    this->blocked.push_back(s);
    isBlocked = true;
  }
  return isBlocked;
}

bool Article13Filter::isCopyrighted(std::string s) {
  return this->copyrighted.find(s) != this->copyrighted.end();
}

std::vector<std::string> Article13Filter::getBlocked() {
  return blocked;
}
