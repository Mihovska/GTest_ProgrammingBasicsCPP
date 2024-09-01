#include "solution.h"

void outputPersons(const std::string &personType,
                   const std::vector<const Participation *> &persons) {
  std::cout << personType << " ";
  for (const auto& participant : persons) {
    std::cout << "- " << participant->getInfo() << std::endl;
  }
}
