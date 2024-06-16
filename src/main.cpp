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
#include <stack>
#include <queue>
#include <locale>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

const char ASTEROID = '#';
const char COMET = '$';
const char EMPTY_SEGMENT = '.';
const char REPLACE_SYMBOL = '+';
const std::vector<char> STARS = {'O', 'B', 'A', 'F', 'G', 'K', 'M', 'L', 'T', 'Y'};

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::vector<char>> matrix;
  std::string line;

  while (std::getline(cin, line) && line != "end") {
    std::vector<char> row(line.begin(), line.end());
    matrix.push_back(row);
  }

  std::string replacements;
  std::getline(cin, replacements);

  std::map<char, int> starCount;
  int planetCount = 0;
  int cometCount = 0;
  int asteroidCount = 0;

  for (const auto &row : matrix) {
    for (auto ch : row) {
      if (ch == ASTEROID) {
        asteroidCount++;
      } else if (ch == COMET) {
        cometCount++;
      } else if (ch >= 1 && ch <= 9) {
        planetCount++;
      } else {
        auto it = std::find(STARS.begin(), STARS.end(), ch);
        if (it != STARS.end()) {
          size_t pos = it - STARS.begin();
          starCount[pos]++;
        }
       }
    }
  }

  int totalStars = 0;
  for (auto &pair : starCount) {
    totalStars += pair.second;
  }



  if (totalStars > 0) {
    cout << "Stars: " << totalStars << std::endl;

    for (const auto &pair : starCount) {
      cout << STARS[pair.first] << ": " << pair.second << std::endl;
    }
  }

  if (planetCount > 0) {
    cout << "Planets: " << planetCount << std::endl;
  }

  if (asteroidCount + cometCount > 0) {
    cout << "Asteroids/comets: " << asteroidCount + cometCount << std::endl;
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
