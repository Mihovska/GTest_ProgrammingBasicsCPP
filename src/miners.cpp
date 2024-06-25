#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
#include <map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::map<std::string, int> resources;
  std::vector<std::string> order;

  std::string input;
  std::string resource;
  int quantity;


  while (std::getline(cin, input) && input != "stop") {
    resource = input;
    std::getline(cin, input);
    quantity = std::stoi(input);

    if (resources.find(resource) == resources.end()) {
      order.push_back(resource);
    }
    resources[resource] += quantity;
  }


  for (const auto &res : order) {
    cout << res << " -> " << resources[res] << std::endl;
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
