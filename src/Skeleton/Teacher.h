#ifndef SRC_SKELETON_TEACHER_H_
#define SRC_SKELETON_TEACHER_H_

#include <vector>
#include <string>

#include "classes.h"

class Teacher : public Person, public Participation {
  std::vector<const Person *> Participation;
 public:
  Teacher(const std::string& firstName, const std::string& secondName)
  : Person(firstName, secondName) {}

  void registerParticipation(const Person *) const override;
  std::string getInfo() const override;
};

#endif  // SRC_SKELETON_TEACHER_H_
