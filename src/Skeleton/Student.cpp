#include "Student.h"

void Student::registerParticipation(const Person* person) const {
  Participation.push_back(person->getId());
}

std::string Student::getInfo() const {
  std::string info = "";
  for (const auto& id : Participation) {
    info+= id + "\n";
  }
  return info;
}
