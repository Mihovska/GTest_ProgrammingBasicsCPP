#ifndef LECTURE_H_
#define LECTURE_H_

#include <map>
#include <set>

#include "Resource.h"
#include "ResourceType.h"

namespace SoftUni {
class Lecture {
  std::set<Resource> resources;
  std::map<ResourceType, int> resourceTypeCounts;

 public:
  Lecture() = default;

  Lecture &operator<<(const Resource &r) {
    auto it = resources.find(r);
    if (it != resources.end()) {
      resourceTypeCounts[r.getType()]--;
      resources.erase(it);
    }
    resources.insert(r);
    resourceTypeCounts[r.getType()]++;
    return *this;
  }

  std::set<Resource>::iterator begin() {
    return resources.begin();
  }

  std::set<Resource>::iterator end() {
    return resources.end();
  }

  const int &operator[](ResourceType type) const {
    auto it = resourceTypeCounts.find(type);
    if (it != resourceTypeCounts.end()) {
      return it->second;
    } else {
      static int zero = 0;
      return zero;
    }
  }

  friend std::vector<ResourceType> &operator<<(std::vector<ResourceType> &types, const Lecture &l);
};

std::vector<ResourceType> &operator<<(std::vector<ResourceType> &types, const Lecture &l) {
  for (const auto &pair : l.resourceTypeCounts) {
    types.push_back(pair.first);
  }
  return types;
}
}  // namespace SoftUni

#endif  // !LECTURE_H_
