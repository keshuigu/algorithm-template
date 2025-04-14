#include "algorithm_template/bits_trick.h"

#include "gtest/gtest.h"

#include <cstdint>
namespace algorithm_template {

TEST(BitTrickTest, IntToString) {
  ASSERT_EQ(IntToBinaryString(0), "00000000000000000000000000000000");
  ASSERT_EQ(IntToBinaryString(1), "00000000000000000000000000000001");
  ASSERT_EQ(IntToBinaryString(-1), "11111111111111111111111111111111");
  int g = 0b0001010;
  int h = 0b0001100;
  int mx = INT32_MAX;
  int mn = INT32_MIN;
  ASSERT_EQ(IntToBinaryString(g | h), "00000000000000000000000000001110");
}

}  // namespace algorithm_template
