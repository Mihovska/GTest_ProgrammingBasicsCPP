#ifndef _COMPARATORS_H_
#define _COMPARATORS_H_

template<typename T>
class LessThan {
 public:
  bool operator()(const T& a, const T& b) const {
    return a < b;
  }
};

template <typename T, typename Comparator = LessThan<T>>
class Reverse {
  Comparator compare;
 public:
  bool operator()(const T&a, const T& b) const {
    return !compare(a, b);
  }
};

#endif  // _COMPARATORS_H_
