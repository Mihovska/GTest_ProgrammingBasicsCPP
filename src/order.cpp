#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <string>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

bool compareCompaniesIds(const std::pair<std::string, int> a,
                         const std::pair<std::string, int> b) {
  return a.second < b.second;
}

void sortCompaniesById(std::vector<std::string>* companyNames,
                       std::vector<int>* companyIds) {
  std::vector<std::pair<std::string, int>> companies;
  for (size_t i = 0; i < companyIds->size(); ++i) {
    companies.emplace_back((*companyNames)[i], (*companyIds)[i]);
  }
  std::sort(companies.begin(), companies.end(), compareCompaniesIds);


  companyNames->clear();
  companyIds->clear();

  for (const auto &company : companies) {
    companyNames->push_back(company.first);
    companyIds->push_back(company.second);
  }
}

int process(std::istream &cin, std::ostream &cout) {
  std::string companyName;
  int id;

  std::vector<std::string> companyNames;
  std::vector<int> companyIds;

  while (true) {
    cin >> companyName;
    if (companyName == "end") {
      break;
    }
    cin >> id;
    companyNames.push_back(companyName);
    companyIds.push_back(id);
  }

  sortCompaniesById(&companyNames, &companyIds);

  for (size_t i = 0; i < companyNames.size(); ++i) {
    cout << companyNames[i] << " " << companyIds[i] << std::endl;
  }

  return 0;
}

int main(int argc, char **argv) {
#ifdef TESTING
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  process(std::cin, std::cout);
  return 0;
#endif
}
