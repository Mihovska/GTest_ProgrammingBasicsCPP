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

#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  std::stack<std::string> flowA;
  std::queue<std::string> flowB;

  std::string fishName;
  std::string flowType;

  while (cin >> fishName && fishName != "end") {
    cin >> flowType;

    if (flowType == "A") {
      flowA.push(fishName);
    } else {
      flowB.push(fishName);
    }
  }

  if (flowA.empty()) {
    cout << "Flow A:" << std::endl << "<EMPTY>" << std::endl;
  } else {
    cout << "Flow A:" << std::endl;
    bool first = true;
    while (!flowA.empty()) {
      if (!first) {
        cout << ", ";
      }
      first = false;

      cout << flowA.top();
      flowA.pop();
    }
    cout << std::endl;
  }


  if (flowB.empty()) {
    cout << "Flow B:" << std::endl << "<EMPTY>" << std::endl;
  } else {
    cout << "Flow B:" << std::endl;

    bool first = true;
    while (!flowB.empty()) {
      if (!first) {
        cout << ", ";
      }
      first = false;
      cout << flowB.front();
      flowB.pop();
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
