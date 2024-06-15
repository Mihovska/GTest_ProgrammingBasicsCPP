#include <algorithm>
#include <array>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <list>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::unordered_map<int, std::vector<std::string>> rooms;
  std::unordered_map<std::string, std::vector<int>> kidToRooms;

  std::string input;

  while (std::getline(cin, input)) {
    if (input == "END") {
      break;
    }

    std::istringstream iss(input);
    std::string name;
    int room;
    iss >> name >> room;

    rooms[room].push_back(name);
    kidToRooms[name].push_back(room);
  }

  while (std::getline(cin, input)) {
    if (input == "END") {
      break;
    }
    if (kidToRooms.find(input) != kidToRooms.end()) {
      cout << input << ":";

      for (const auto &room : kidToRooms[input]) {
        cout << " " << room;
      }
      cout << std::endl;
    } else {
      cout << input << ": Not found!" << std::endl;
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
