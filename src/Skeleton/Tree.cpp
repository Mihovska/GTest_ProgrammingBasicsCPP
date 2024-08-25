#include "Tree.h"


void Tree::outputTree(std::ostream &out) const {
  out << ++cnt << ". " << getName() << " tree with " << getLeaves()
      << " leaves, which produces "
      << getProduction() << " and is great for "
      << getGreatness() << "." << std::endl;
}
