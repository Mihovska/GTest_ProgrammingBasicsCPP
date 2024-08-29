#ifndef SRC_SKELETON_VECTORCOMPARISONS_H_
#define SRC_SKELETON_VECTORCOMPARISONS_H_

#include "Vector.h"

class VectorLengthComparer {
 public:
  bool operator()(const Vector& a, const Vector& b) const {
    return a.getLength() < b.getLength();
  }
};

template <typename T, typename Compare>
class ReverseComparer {
 public:
  bool operator()(const T& a, const T& b) const {
    return !Compare()(a, b);
  }
};

#endif  // SRC_SKELETON_VECTORCOMPARISONS_H_
