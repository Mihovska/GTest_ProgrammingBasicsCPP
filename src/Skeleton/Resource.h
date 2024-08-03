#ifndef RESOURCE_H_
#define RESOURCE_H_

#include <iostream>
#include <string>
#include <vector>

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

  ResourceType getType() const { return type; }

  int getId() const { return id; }

  const std::string &getLink() const { return link; }

  friend std::istream &operator>>(std::istream &in, Resource &r);

  friend std::ostream &operator<<(std::ostream &out, const Resource &r);

  bool operator<(const Resource &other) const {
    if (this->id == other.id) {
      return false;
    }
    return this->id < other.id;
  }
};

std::istream &operator>>(std::istream &in, Resource &r) {
  int id;
  std::string type;
  std::string link;

  in >> id >> type >> link;

  r.id = id;
  r.link = link;

  if (type == "Presentation") {
    r.type = ResourceType::PRESENTATION;
  } else if (type == "Demo") {
    r.type = ResourceType::DEMO;
  } else if (type == "Video") {
    r.type = ResourceType::VIDEO;
  }

  return in;
}

std::ostream &operator<<(std::ostream &out, const Resource &r) {
  out << r.id << " " << r.type << " " << r.link;
  return out;
}
}  // namespace SoftUni

#endif  // !RESOURCE_H_
