#ifndef SRC_SKELETON_ORDEREDINSERTER_H_
#define SRC_SKELETON_ORDEREDINSERTER_H_

#include <vector>
#include "Company.h"

class OrderedInserter {
  std::vector<const Company*> &companies;

 public:
  explicit OrderedInserter(std::vector<const Company*> &companies)
  : companies(companies) {}

  void insert(const Company* company) {
    auto it = companies.begin();
    while (it != companies.end() && (*it)->getId() < company->getId()) {
      ++it;
    }
    companies.insert(it, company);
  }
};

#endif  // SRC_SKELETON_ORDEREDINSERTER_H_
