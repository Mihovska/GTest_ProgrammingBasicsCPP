#ifndef TREE_H_
#define TREE_H_

#include <string>
#include <memory>
#include <list>
#include <iostream>

class Tree {
 public:
  Tree() = default;
  static size_t cnt;

  virtual const std::string getName() const = 0;
  virtual const std::string getLeaves() const = 0;
  virtual const std::string getProduction() const = 0;
  virtual const std::string getGreatness() const = 0;

  virtual void outputTree(std::ostream &out) const;

  virtual ~Tree() = default;
};
#endif  // TREE_H_
