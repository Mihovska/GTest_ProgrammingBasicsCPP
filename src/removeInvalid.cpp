#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstddef>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

bool isValidId(int id) {
  return id >= 0;
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::string> companyNames;
  std::vector<int> companyIds;

  std::string companyName;

  while (true) {
    std::getline(cin, companyName);
    if (companyName == "end") {
      break;
    }

    std::istringstream iss(companyName);
    std::string name;
    int id;
    iss >> id >> name;

    companyIds.push_back(id);
    companyNames.push_back(name);
  }

  bool (*isValidPtr)(int) = isValidId;

  for (size_t i = 0; i < companyIds.size(); ++i) {
    if (isValidPtr(companyIds[i])) {
      cout << companyIds[i] << " " << companyNames[i] << std::endl;
    }
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
