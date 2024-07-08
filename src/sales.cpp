#include <algorithm>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

class Sale {
 public:
  std::string town;
  std::string product;
  double price;
  double quantity;

  Sale(const std::string &town, const std::string &product, double price, double quantity) :
  town(town), product(product), price(price), quantity(quantity) {}

  static void readSales(std::vector<Sale> &sales, int numberOfSales) {
    for (int i = 0; i < numberOfSales; ++i) {
      std::string town;
      std::string product;
      double price;
      double quantity;
      std::cin >> town >> product >> price >> quantity;

      sales.emplace_back(Sale(town, product, price, quantity));
    }
  }

  std::map<std::string, double> calculateTotalSalesByTown(const std::vector<Sale> &sales) {
    std::map<std::string, double> totalSalesByTown;

    for (const auto &sale : sales) {
      totalSalesByTown[sale.town] += sale.price * sale.quantity;
    }

    return totalSalesByTown;
  }

  void printTotalSalesByTown(const std::map<std::string, double> &salesByTown) {
    std::vector<std::pair<std::string, double>> salesByTownSorted(salesByTown.begin(), salesByTown.end());

    std::sort(salesByTownSorted.begin(), salesByTownSorted.end());

    for (const auto &sale : salesByTownSorted) {
      std::cout << sale.first << " -> " << std::fixed << std::setprecision(2) << sale.second << std::endl;
    }
  }
};

int process(std::istream &cin, std::ostream &cout) {
  int n;
  cin >> n;

  std::vector<Sale> sales;
  Sale::readSales(sales, n);

  Sale sale("", "", 0, 0);

  std::map<std::string, double> totalSalesByTown = sale.calculateTotalSalesByTown(sales);
  sale.printTotalSalesByTown(totalSalesByTown);

  return 0;
}

int main(int argc, char **argv) {
#ifdef TESTING
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
#else
  process(std::cin, std::cout);
  return 0;
#endif
}
