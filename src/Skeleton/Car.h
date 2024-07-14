#ifndef CAR_H
#define CAR_H

#include <string>
using namespace std;

class Car {
 public:
  string Brand;
  string Model;
  int Year;

  Car(const string &brand, const string &model, const int &year) :
      Brand(brand), Model(model), Year(year) {}

  string GetBrand() const {
    return Brand;
  }

  string GetModel() const {
    return Model;
  }

  int GetYear() const {
    return Year;
  }
};

#endif  //  !CAR_H

