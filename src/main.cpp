#include <iostream>
#include <iomanip>
#include <string>

#ifdef TESTING
#include <gtest/gtest.h>
#endif

void process(std::istream &in, std::ostream &out) {
    const double taxiStartPrice = 0.70;
    const double taxiDayPrice = 0.79;
    const double taxiNightPrice = 0.90;
    const double busPrice = 0.09; // can be used for distance of minimum of 20km
    const double trainPrice = 0.06; // can be used for distance of minimum of 100km

    int kmCount = 0;
    std::string dayOrNight;
    in >> kmCount >> dayOrNight;

    double lowestPrice = 0.0;

    if (kmCount < 20) {
        double taxiPrice;
        if (dayOrNight == "day"){
            taxiPrice = taxiDayPrice * kmCount;
        }
        if (dayOrNight == "night"){
            taxiPrice = taxiNightPrice * kmCount;
        }
        lowestPrice = taxiStartPrice + taxiPrice;
    } else if (kmCount >= 100) {
        lowestPrice = kmCount * trainPrice;
    } else {
        lowestPrice = kmCount * busPrice;
    }

    out.setf(std::ios::fixed);
    out.precision(2);
    out << lowestPrice << std::endl;
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
