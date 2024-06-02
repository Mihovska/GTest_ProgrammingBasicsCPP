#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <stack>
#include <iostream>
#include <sstream>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::stack<int> clothes;
  std::string clothesInput;
  std::getline(cin, clothesInput);
  std::istringstream iss(clothesInput);

  std::string pieceOfClothes;
  while (iss >> pieceOfClothes) {
    clothes.push(stoi(pieceOfClothes));
  }

  int rackCapacity = 0;
  cin >> rackCapacity;

  int racksNeeded = 0;
  int sum = 0;

  while (!clothes.empty()) {
    int currentClothes = clothes.top();
    clothes.pop();

    if (sum + currentClothes > rackCapacity) {
      racksNeeded++;
      sum = currentClothes;
    } else if (sum + currentClothes == rackCapacity) {
      racksNeeded++;
      sum = 0;
    } else {
      sum += currentClothes;
    }
  }
  if (sum > 0) {
    racksNeeded++;
  }

  cout << racksNeeded << std::endl;

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
