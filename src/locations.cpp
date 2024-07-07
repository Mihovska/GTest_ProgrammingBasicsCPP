#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class LocationDatabase {
 private:
  std::map<std::string, std::string> namesToCoordinates;
  std::map<std::string, std::vector<std::string>> coordinatesToNames;

 public:
  void addLocation(const std::string &name, const std::string &latitude, const std::string &longitude) {
    std::string coordinates = latitude + ',' + longitude;
    namesToCoordinates[name] = coordinates;
    coordinatesToNames[coordinates].push_back(name);
  }

  std::string getCoordinates(const std::string &name) const {
    auto it = namesToCoordinates.find(name);
     return it != namesToCoordinates.end() ? it->second : "";
  }

  const std::vector<std::string>& getNames(const std::string &coordinates) const {
    static const std::vector<std::string> empty;
    auto it = coordinatesToNames.find(coordinates);
     return it != coordinatesToNames.end() ? it->second : empty;
  }
};

class LocationProcessor {
 private:
  LocationDatabase &database;
  std::istream &input;
  std::ostream &output;

 public:
  LocationProcessor(LocationDatabase &db, std::istream &in, std::ostream &out)
        : database(db), input(in), output(out) {}

    void process() {
        std::string line;

        while (std::getline(input, line) && line != ".") {
            std::istringstream iss(line);
            std::string name, latitude, longitude;
            std::getline(iss, name, ',');
            std::getline(iss, latitude, ',');
            std::getline(iss, longitude);
            database.addLocation(name, latitude, longitude);
        }

        while (std::getline(input, line) && line != ".") {
            std::istringstream iss(line);
            std::string locationName, coordinatesString;
            iss >> locationName >> coordinatesString;

            if (coordinatesString.empty()) {
                std::string coords = database.getCoordinates(locationName);
                if (!coords.empty()) {
                    output << locationName << "," << coords << std::endl;
                }
            } else {
                std::string coordinates = locationName + ',' + coordinatesString;
                const auto& names = database.getNames(coordinates);
                for (const auto &name : names) {
                    output << name << "," << coordinates << std::endl;
                }
            }
        }
    }
};

int process(std::istream &cin, std::ostream &cout) {
  LocationDatabase database;
  LocationProcessor processor(database, cin, cout);
  processor.process();
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
