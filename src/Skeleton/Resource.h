#ifndef RESOURCE_H_
#define RESOURCE_H_



#include <iostream>
#include <vector>
#include <string>

#include "ResourceType.h"

namespace SoftUni {
class Resource {
  int id = 0;
  ResourceType type = ResourceType::PRESENTATION;
  std::string link = "";

 public:
  Resource() = default;
  Resource(int id, ResourceType type, std::string &link) : id(id), type(type), link(link) {}

  ResourceType getType() const {
    return type;
  }

  friend std::istream &operator>>(std::istream &in, Resource &r);

  friend std::ostream &operator<<(std::ostream &out, const Resource &r);
};

  std::istream &operator>>(std::istream &in, Resource &r) {
    in >> r.id >> r.type >> r.link;
    return in;
  }

  std::ostream &operator<<(std::ostream &out, const Resource &r) {
    out << r.id << r.type << r.link;
    return out;
  }
}  // namespace SoftUni

#endif  // !RESOURCE_H_
