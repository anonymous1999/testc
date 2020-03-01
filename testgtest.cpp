#include "gtest/gtest.h"
int foo ()
{
    return 0;
}
TEST(FooTest, test)
{
    EXPECT_EQ(0, foo());
}
int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}