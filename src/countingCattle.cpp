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

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void printCows(std::list<std::string> &cows, double avgCows,
               std::ostream &cout) {
  if (cows.size() == 0) {
    cout << "no cows!" << std::endl;
  } else {
    cout << cows.size() << " cows: ";
    for (auto cow : cows) {
      cout << cow << " ";
    }
    cout << "with avg. size " << std::fixed << std::setprecision(2) << avgCows
         << std::endl;
  }
}

void printSheep(std::list<std::string> &sheep, double avgSheep,
                std::ostream &cout) {
  if (sheep.size() == 0) {
    cout << "no sheep!" << std::endl;
  } else {
    cout << sheep.size() << " sheep: ";
    for (auto sheep : sheep) {
      cout << sheep << " ";
    }
    cout << "with avg. size " << std::fixed << std::setprecision(2) << avgSheep
         << std::endl;
  }
}

void printOthers(std::list<std::string> &others, double avgOthers,
                 std::ostream &cout) {
  if (others.size() == 0) {
    cout << "no others!" << std::endl;
  } else {
    cout << others.size() << " others: ";
    for (auto other : others) {
      cout << other << " ";
    }
    cout << "with avg. size " << std::fixed << std::setprecision(2) << avgOthers
         << std::endl;
  }
}

int process(std::istream &cin, std::ostream &cout) {
  std::list<std::string> cows, sheep, others;
  std::string input;
  std::getline(cin, input);

  int cowsSizeSum = 0;
  int sheepSizeSum = 0;
  int othersSizeSum = 0;

  std::istringstream iss(input);
  std::string word;
  while (iss >> word) {

    char type = word[0];
    int size = word[1] - '0';

    switch (type) {
    case 'C':
      cows.push_back(word);
      cowsSizeSum += size;
      break;
    case 'S':
      sheep.push_back(word);
      sheepSizeSum += size;
      break;
    default:
      others.push_back(word);
      othersSizeSum += size;
    }
  }

  double avgCows = cowsSizeSum * 1.0 / cows.size();
  double avgSheep = sheepSizeSum * 1.0 / sheep.size();
  double avgOthers = othersSizeSum * 1.0 / others.size();

  printCows(cows, avgCows, cout);
  printSheep(sheep, avgSheep, cout);
  printOthers(others, avgOthers, cout);

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
