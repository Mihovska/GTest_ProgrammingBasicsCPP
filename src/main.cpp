#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <string>
#include <cstring>
#include <cstddef>
#include <map>


#ifdef TESTING
#include <gtest/gtest.h>
#endif


int process(std::istream &cin, std::ostream &cout) {
  std::map<std::string, std::string> namesToCoordinates;
  std::map<std::string, std::vector<std::string>> coordinatesToNames;
  std::string input;

  while (std::getline(cin, input) && input != ".") {
    std::istringstream iss(input);
    std::string name;
    std::string latitude;
    std::string longitude;

    std::getline(iss, name, ',');
    std::getline(iss, latitude, ',');
    std::getline(iss, longitude);

    std::string coordinates = latitude + ',' + longitude;

    namesToCoordinates[name] = coordinates;
    coordinatesToNames[coordinates].push_back(name);
  }

  while (std::getline(cin, input) && input != ".") {
    std::istringstream iss(input);
    std::string locationName;
    std::string coordinatesString;

    iss >> locationName >> coordinatesString;

    if (coordinatesString.empty() &&
        namesToCoordinates.find(locationName) != namesToCoordinates.end()) {
      std::string coords = namesToCoordinates[locationName];
      std::string name = locationName;

      cout << name << "," << coords << std::endl;
    } else {
      std::stringstream coordinateStream;
      coordinateStream << locationName << ',' << coordinatesString;
      std::string coordinates = coordinateStream.str();

      if (coordinatesToNames.find(coordinates) != coordinatesToNames.end()) {
        for (const std::string &nameCoord : coordinatesToNames[coordinates]) {
          cout << nameCoord << "," << coordinates << std::endl;
        }
      }
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
