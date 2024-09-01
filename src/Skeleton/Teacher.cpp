#include "Teacher.h"

void Teacher::registerParticipation(const Person * person) const {
  Participation.push_back(person->getId());
}

std::string Teacher::getInfo() const {
  std::string info = "";
  for (const auto& id : Participation) {
    info += id + "\n";
  }
  return info;
}
