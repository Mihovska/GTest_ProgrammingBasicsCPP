#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <map>
#include <iostream>
#include <iomanip>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

int process(std::istream &cin, std::ostream &cout) {
  int count = 0;
  cin >> count;

  std::map<std::string, std::vector<double>> studentsGrades;

  for (int i = 0; i < count; ++i) {
    std::string name;
    double grade = 0.0;
    cin >> name >> grade;

    studentsGrades[name].push_back(grade);
  }

  for (const auto &student : studentsGrades) {
    const auto &name = student.first;
    const std::vector<double> &grades = student.second;
    double sum = 0.0;

    for (const auto &grade : grades) {
      sum += grade;
    }
    double average = sum / grades.size();

    cout << name << " -> ";
    cout << std::fixed << std::setprecision(2);
    for (const auto &grade : grades) {
      cout << grade << " ";
    }
    cout << "(avg: " << average << ")" << std::endl;
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
