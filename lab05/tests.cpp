#include <gtest/gtest.h>

#include "./include/myqueue.hpp"

TEST(MyQueueTest, EnqueueAndDequeue) {
    MyQueue<int, 3> queue;

    ASSERT_TRUE(queue.empty());

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    ASSERT_EQ(queue.size(), 3);
    ASSERT_EQ(queue.front(), 1);

    queue.dequeue();
    ASSERT_EQ(queue.size(), 2);
    ASSERT_EQ(queue.front(), 2);

    queue.dequeue();
    ASSERT_EQ(queue.size(), 1);
    ASSERT_EQ(queue.front(), 3);

    queue.dequeue();
    ASSERT_TRUE(queue.empty());
}

TEST(MyQueueTest, Iterator) {
    MyQueue<int, 3> queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    int sum = 0;
    for (const auto& value : queue) {
        sum += value;
    }

    ASSERT_EQ(sum, 6);
}

TEST(MyQueueTest, Contains) {
    MyQueue<std::string, 3> queue;

    queue.enqueue("apple");
    queue.enqueue("banana");
    queue.enqueue("orange");

    ASSERT_TRUE(queue.contains("banana"));
    ASSERT_FALSE(queue.contains("grape"));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}