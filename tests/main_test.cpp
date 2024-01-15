#include <gtest/gtest.h>
#include <sstream>
#include "main.cpp"

struct ProgrammingBasicsTestParam {
    std::string input;
    std::string expectedOutput;
};

class PBTest : public ::testing::TestWithParam<ProgrammingBasicsTestParam> {
};

TEST_P(PBTest, Test) {
    ProgrammingBasicsTestParam param = GetParam();

// Prepare input and output streams
std::istringstream input(param.input);
std::ostringstream output;

// Call main function
process(input, output);

// Check output
EXPECT_EQ(output.str(), param.expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        ProgrammingBasicsTests,
        PBTest,
        ::testing::Values(
        ProgrammingBasicsTestParam{"5 day", "4.65\n"},
        ProgrammingBasicsTestParam{"7 night", "7.00\n"},
        ProgrammingBasicsTestParam{"25 day", "2.25\n"},
        ProgrammingBasicsTestParam{"180 night", "10.80\n"}
)
);
