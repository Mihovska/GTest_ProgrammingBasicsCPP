#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <ostream>
#include <sstream>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void printCattle(std::list<std::string> &cattles, double &avgCattles,
                 std::string type, std::ostream &cout) {
  if (cattles.empty()) {
    cout << "no " << type << "!" << std::endl;
  } else {
    cout << cattles.size() << " " << type << ": ";
    for (auto cattle : cattles) {
      cout << cattle << " ";
    }
    cout << "with avg. size " << std::fixed << std::setprecision(2)
         << avgCattles << std::endl;
  }
}

double calculateAverage(std::list<std::string> &cattles, double sizeSum) {
  return sizeSum * 1.0 / cattles.size();
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

  double avgCows = calculateAverage(cows, cowsSizeSum);
  double avgSheep = calculateAverage(sheep, sheepSizeSum);
  double avgOthers = calculateAverage(others, othersSizeSum);

  printCattle(cows, avgCows, "cows", cout);
  printCattle(sheep, avgSheep, "sheep", cout);
  printCattle(others, avgOthers, "others", cout);

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
