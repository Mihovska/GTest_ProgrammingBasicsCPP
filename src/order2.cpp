#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstddef>


#ifdef TESTING
#include <gtest/gtest.h>
#endif

bool compareCompaniesIds(const std::vector<char> &buffer,
                         std::size_t a, std::size_t b) {
  int aId;
  int bId;

  memcpy(&aId, buffer.data() + a, sizeof(aId));
  memcpy(&bId, buffer.data() + b, sizeof(bId));

  return aId < bId;
}

int process(std::istream &cin, std::ostream &cout) {
  std::string companyName;
  int id;

  std::vector<char> buffer;
  std::vector<size_t> buffer_pos;

  while (true) {
    cin >> companyName;
    if (companyName == "end") {
      break;
    }
    cin >> id;

    std::size_t newSize = sizeof(id) + companyName.size() + 1;
    std::size_t currentSize = buffer.size();
    buffer.resize(currentSize + newSize);
    char *currentPos = buffer.data() + currentSize;
    buffer_pos.push_back(currentSize);
    int *idPos = reinterpret_cast<int *>(currentPos);
    *idPos = id;
    std::copy(companyName.begin(), companyName.end(), currentPos + sizeof(id));
  }

  std::sort(buffer_pos.begin(), buffer_pos.end(),
            [&buffer](std::size_t a, std::size_t b) {
            return compareCompaniesIds(buffer, a, b);
  });

  for (std::size_t offset : buffer_pos) {
    const int *idPos = reinterpret_cast<const int *>(buffer.data() + offset);
    const char *namePos = buffer.data() + offset + sizeof(*idPos);
    cout << namePos << " " << *idPos << std::endl;
  }

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
