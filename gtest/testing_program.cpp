#include <gtest/gtest.h>
#include "my_program.cpp"


TEST(SquareRootTest, PosParam) {
    ASSERT_NEAR(2, my_root(4), 1e-6);
    ASSERT_NEAR(1.732050, my_root(3), 1e-6);
    ASSERT_NEAR(351.36306, my_root(123456), 1e-6);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
