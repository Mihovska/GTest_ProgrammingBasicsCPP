#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>

#include "ResourceType.h"

namespace SoftUni {
class Resource {
  int id = 0;
  ResourceType type = ResourceType::PRESENTATION;
  std::string link = "";

 public:
  Resource() = default;
  Resource(int id, const ResourceType &type, const std::string &link)
      : id(id), type(type), link(link) {}

  friend std::istream &operator>>(std::istream &in, Resource &r);

  friend std::ostream &operator<<(std::ostream &out, const Resource &r);

  int getId() const { return id; }

  ResourceType getType() const { return type; }

  bool operator<(const Resource &other) const {
    return this->id < other.id;
  }
};

std::istream &operator>>(std::istream &in, Resource &r) {
  int id;
  std::string type, link;

  in >> id >> type >> link;
  r.id = id;
  r.link = link;

  if (type == "Presentation") {
    r.type = ResourceType::PRESENTATION;
  } else if (type == "Video") {
    r.type = ResourceType::VIDEO;
  } else if (type == "Demo") {
    r.type = ResourceType::DEMO;
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const Resource &r) {
  out << r.getId() << " " << r.getType() << " " << r.link;
  return out;
}

}  // namespace SoftUni
#endif  // !RESOURCE_H
