#ifndef SRC_SKELETON_FIND_H_
#define SRC_SKELETON_FIND_H_

#include <string>
#include <vector>
#include "Company.h"

Company* find(const std::vector<Company*> &companies, int id) {
  for (Company* company : companies) {
    if (company->getId() == id) {
      return company;
    }
  }
  return nullptr;
}

#endif  // SRC_SKELETON_FIND_H_
