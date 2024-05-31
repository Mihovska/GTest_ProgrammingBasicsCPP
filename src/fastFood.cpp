#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <queue>
#include <iostream>
#include <sstream>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int findMaxElement(std::queue<int> &orders) {
  int maxOrder = INT_MIN;
  std::queue<int> temp;

  while (!orders.empty()) {
    int currentOrder = orders.front();
    orders.pop();
    if (currentOrder > maxOrder) {
      maxOrder = currentOrder;
    }
    temp.push(currentOrder);
  }
  while (!temp.empty()) {
    orders.push(temp.front());
    temp.pop();
  }
  return maxOrder;
}

int process(std::istream &cin, std::ostream &cout) {
  int foodQuantity = 0;
  cin >> foodQuantity;
  cin.ignore();

  std::queue<int> orders;

  std::string inputOrders;
  std::getline(cin, inputOrders);
  std::istringstream iss(inputOrders);
  std::string order;
  while (iss >> order) {
    orders.push(stoi(order));
  }

  cout << findMaxElement(orders) << std::endl;

  std::queue<int> ordersLeft;
  while (foodQuantity > 0 && !orders.empty()) {
    int curOrder = orders.front();
    if (foodQuantity >= curOrder) {
      orders.pop();
      foodQuantity -= curOrder;
    } else {
      ordersLeft.push(curOrder);
      orders.pop();
      foodQuantity = 0;
    }
  }

  if (!ordersLeft.empty()) {
    cout << "Orders left: ";
    while (!ordersLeft.empty()) {
      cout << ordersLeft.front();
      ordersLeft.pop();
    }
    cout << std::endl;
  } else {
    cout << "Orders complete" << std::endl;
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
