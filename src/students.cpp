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

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class Student {
 public:
  std::string studentName;
  std::string studentSurname;
  double average;

  Student(const std::string &studentName,
          const std::string &studentSurname,
          double average) :
          studentName(studentName), studentSurname(studentSurname), average(average) {}
  void print(std::ostream &cout) const {
    cout << studentName << " " << studentSurname << " " << average << std::endl;
  }
};

double calculateTotalAverageOfAllStudents(const std::vector<Student> &students) {
  double totalAverage = 0.;

  for (const auto &student : students) {
    totalAverage += student.average;
  }
  totalAverage /= students.size();

  return totalAverage;
}

int process(std::istream &cin, std::ostream &cout) {
  int numberOfStudents;
  cin >> numberOfStudents;

  if (numberOfStudents <= 0) {
    cout << "Invalid input" << std::endl;
    return 1;
  }

  std::vector<Student> students;
  for (int i = 0; i < numberOfStudents; ++i) {
    std::string studentName;
    std::string studentSurname;
    double average;

    cin >> studentName >> studentSurname >> average;
    students.emplace_back(studentName, studentSurname, average);
  }

  for (const auto &student : students) {
    student.print(cout);
  }

  double totalAverage = calculateTotalAverageOfAllStudents(students);
  cout << totalAverage << std::endl;

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
