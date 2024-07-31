#include <iostream>
#include <map>
#include <set>
#include <vector>


#include "Resource.h"
#include "ResourceType.h"


int main() {
  using SoftUni::Resource;
  using SoftUni::ResourceType;

  std::set<Resource> resources;
  std::map<ResourceType, int> numberOfResourcesByType;

  int numResources;

  std::cin >> numResources;

  for (int i = 0; i < numResources; i++) {
    Resource r;

    std::cin >> r;

    resources.insert(r);
  }

  for (const auto r : resources) {
    numberOfResourcesByType[r.getType()]++;
  }

  std::cout << "... by id:" << std::endl;

  for (const auto r : resources) {
    std::cout << r << std::endl;
  }

  std::cout << "... by type:" << std::endl;
  for (auto pair : numberOfResourcesByType) {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }

  return 0;
}
