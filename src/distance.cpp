#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <iomanip>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class Point {
  double x;
  double y;

 public:
  Point(double x, double y) : x(x), y(y) {}

  double distance(const Point &other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
  }
};

int process(std::istream &cin, std::ostream &cout) {
  double x1;
  double y1;
  double x2;
  double y2;

  cin >> x1 >> y1;
  cin >> x2 >> y2;

  Point p1(x1, y1);
  Point p2(x2, y2);

  double distance = p1.distance(p2);

  cout << std::fixed << std::setprecision(3) << distance << std::endl;

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
