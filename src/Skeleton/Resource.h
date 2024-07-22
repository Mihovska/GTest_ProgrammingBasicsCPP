#ifndef RESOURCE_H
#define RESOURCE_H

#include <iostream>
#include <string>

#include "ResourceType.h"

namespace SoftUni {
 class Resource {
  public:
   Resource() = default;

  friend std::istream &operator>>(std::istream &in, Resource &r) {
    in >> r.id;
    std::string type;
    in >> type;
    if (type == "Presentation") {
      r.type = ResourceType::PRESENTATION;
    } else if (type == "Demo") {
      r.type = ResourceType::DEMO;
    } else if (type == "Video") {
      r.type = ResourceType::VIDEO;
    }
    return in;
  }

  friend std::ostream &operator<<(std::ostream &out, const Resource &r) {
    out << r.id << " ";
    switch (r.type) {
      case ResourceType::PRESENTATION:
      out << "Presentation";
      break;
      case ResourceType::DEMO:
      out << "Demo";
      break;
      case ResourceType::VIDEO:
      out << "Video";
      break;
    }

    out << " " << r.link;
    return out;
  }

  int getId() const {
     return id;
  }

  ResourceType getType() const {
    return type;
  }

  private:
   int id;
   ResourceType type;
   std::string link;
  };
}
#endif // !RESOURCE_H
