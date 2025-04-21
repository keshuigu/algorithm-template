#include "algorithm_template/queue.h"

#include "gtest/gtest.h"
namespace algorithm_template {
TEST(QueueTest, MyCircularQueueTest) {
  MyCircularQueue q(3);
  ASSERT_TRUE(q.enQueue(1));
  ASSERT_TRUE(q.enQueue(2));
  ASSERT_TRUE(q.enQueue(3));
  ASSERT_FALSE(q.enQueue(4));
  ASSERT_EQ(3, q.Rear());
  ASSERT_TRUE(q.isFull());
  ASSERT_TRUE(q.deQueue());
  ASSERT_TRUE(q.enQueue(4));
  ASSERT_EQ(4, q.Rear());
}

TEST(QueueTest, MyCircularDequeTest) {
  MyCircularDeque q(3);
  ASSERT_TRUE(q.insertLast(1));
  ASSERT_TRUE(q.insertLast(2));
  ASSERT_TRUE(q.insertFront(3));
  ASSERT_FALSE(q.insertFront(4));
  ASSERT_EQ(2, q.getRear());
  ASSERT_TRUE(q.isFull());
  ASSERT_TRUE(q.deleteLast());
  ASSERT_TRUE(q.insertFront(4));
  ASSERT_EQ(4, q.getFront());
}

TEST(QueueTest, MyQueueTest) {
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  ASSERT_EQ(1, q.pop());
  q.push(5);
  ASSERT_EQ(2, q.pop());
  ASSERT_EQ(3, q.pop());
  ASSERT_EQ(4, q.pop());
  ASSERT_EQ(5, q.pop());
}
}  // namespace algorithm_template