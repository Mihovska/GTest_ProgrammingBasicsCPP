#include <algorithm>
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
#include <unordered_set>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

const char ASTEROID = '#';
const char COMET = '$';
const char EMPTY_SEGMENT = '.';
const char REPLACE_SYMBOL = '+';
const std::unordered_set<char> STARS = {'O', 'B', 'A', 'F', 'G', 'K', 'M', 'L', 'T', 'Y'};

std::vector<std::vector<char>> readMatrix(std::istream &cin) {
  std::vector<std::vector<char>> matrix;
  std::string line;

  while (std::getline(cin, line) && line != "end") {
    std::vector<char> row(line.begin(), line.end());
    matrix.push_back(row);
  }

  return matrix;
}

void countElements(std::vector<std::vector<char>> &matrix, std::map<char, int> &starCount,
                   int &planetCount, int &cometCount, int &asteroidCount) {
  for (const auto &row : matrix) {
    for (auto ch : row) {
      if (ch == ASTEROID) {
        asteroidCount++;
      } else if (ch == COMET) {
        cometCount++;
      } else if (std::isdigit(ch)) {
        planetCount += ch - '0';
      } else if (STARS.count(ch)) {
        starCount[ch]++;
      }
    }
  }
}

int process(std::istream &cin, std::ostream &cout) {
  std::vector<std::vector<char>> matrix = readMatrix(cin);

  std::string replacements;
  std::getline(cin, replacements);

  std::map<char, int> starCount;

  int planetCount = 0;
  int cometCount = 0;
  int asteroidCount = 0;

  countElements(matrix, starCount, planetCount, cometCount, asteroidCount);

  int totalStars = 0;
  if (!starCount.empty()) {
    for (const auto &[firstPairStar, secondPairStar] : starCount) {
      totalStars += secondPairStar;
    }
  }

  if (totalStars >= 0) {
    cout << "Stars: " << totalStars << std::endl;

    for (const auto &[firstPair, secondPair] : starCount) {
      cout << "- " << firstPair << ": " << secondPair << std::endl;
    }
  }

  if (planetCount >= 0) {
    cout << "Planets: " << planetCount << std::endl;
  }

  if (asteroidCount + cometCount >= 0) {
    cout << "Asteroids/comets: " << asteroidCount + cometCount << std::endl;
  }

  std::vector<std::vector<char>> newMatrix = matrix;

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      char currentChar = matrix[i][j];
      if (replacements.find(currentChar) != std::string::npos) {
        newMatrix[i][j] = REPLACE_SYMBOL;
      }
      cout << newMatrix[i][j];
    }
    cout << std::endl;
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
