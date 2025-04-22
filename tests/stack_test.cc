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

TEST(StackTest, MinStackTest) {
  MinStack st;
  st.push(-2);
  st.push(0);
  st.push(-3);
  ASSERT_EQ(-3, st.getMin());
  st.pop();
  ASSERT_EQ(0, st.top());
  ASSERT_EQ(-2, st.getMin());
}

}  // namespace algorithm_template