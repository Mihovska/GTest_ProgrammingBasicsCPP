#ifndef LECTURE_H_
#define LECTURE_H_

#include <iostream>
#include <map>
#include <vector>

#include "Resource.h"
#include "ResourceType.h"

namespace SoftUni {
class Lecture {
  std::vector<Resource> resources;
  std::map<ResourceType, int> resourceTypeCounts;

 public:
  Lecture() = default;

  Lecture &operator<<(const Resource &r) {
    resources.push_back(r);
    resourceTypeCounts[r.getType()]++;
    return *this;
  }

  std::vector<Resource>::iterator begin() { return resources.begin(); }

  std::vector<Resource>::iterator end() { return resources.end(); }

  const int &operator[](ResourceType type) const {
    return resourceTypeCounts.at(type);
  }

  friend std::vector<ResourceType> &operator<<(std::vector<ResourceType> &types,
                                               const Lecture &lecture) {
    for (const auto &pair : lecture.resourceTypeCounts) {
      types.push_back(pair.first);
    }
    return types;
  }
};
}  // namespace SoftUni

#endif  // !LECTURE_H_
