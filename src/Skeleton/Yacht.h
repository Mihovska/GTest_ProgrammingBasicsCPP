#ifndef SRC_SKELETON_YACHT_H_
#define SRC_SKELETON_YACHT_H_

#include <string>

#include "Dockable.h"
#include "Supplemental.h"

class Yacht : public Dockable {
  std::string name;
  Supplements supplies;
  Supplements passengers;
 public:
  Yacht() = default;
  Yacht(const std::string &name) : name(name) {}

  std::string getName() const { return name; }
  std::string getInfo() const;

  std::string dock() const override;
  std::string undock() const override;
  bool onSupplementArrival(Supplement *s) override;

  virtual ~Yacht() = default;
};

#endif  // SRC_SKELETON_YACHT_H_
