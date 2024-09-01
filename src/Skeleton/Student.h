#ifndef SRC_SKELETON_STUDENT_H_
#define SRC_SKELETON_STUDENT_H_

#include <string>
#include <vector>
#include "classes.h"

class Student: public Person, public Participation {
  std::vector<const Person *> Participation;
 public:
  Student(const std::string& firstName, const std::string& secondName) :
  Person(firstName, secondName) {}

  void registerParticipation(const Person *) const override;
  std::string getInfo() const override;
};

#endif  // SRC_SKELETON_STUDENT_H_
