#include "algorithm_template/stack.h"

#include "gtest/gtest.h"
namespace algorithm_template {
TEST(StackTest, MyStackTest) {
  MyStack st;
  st.push(1);
  st.push(2);
  st.push(3);
  ASSERT_EQ(3, st.top());
}


}  // namespace algorithm_template