#include "gtest/gtest.h"

#include "entry.h"
#include "data.h"

/* Single publish. Alice's timeline request should return all Alice's posts */
TEST(Data, Test1) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline.size(), 1u);
}

/* Single publish. Alice timeline request should return posts owned by Alice  */
TEST(Data, Test2) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[0].user, "Alice");
}

/* Single publish. Alice timeline request should return Alice's post content */
TEST(Data, Test3) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[0].message, "I love the weather today.");
}

/* Single publish. Alice timeline request should return the time of Alice's post */
TEST(Data, Test4) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[0].timestamp, t_time);
}

/* Multiple publish.  Alice's timeline request should return all Alice's posts */
TEST(Data, Test5) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    t_data.publish("Alice", "I love the weather again.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline.size(), 2u);
}

/* Multiple publish. Alice timeline request should return posts owned by Alice */
TEST(Data, Test6) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    t_data.publish("Alice", "I love the weather again.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[0].user, "Alice");
    EXPECT_EQ(t_timeline[1].user, "Alice");
}

/* Multiple publish. Alice timeline request should return correct post content */
TEST(Data, Test7) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    t_data.publish("Alice", "I love the weather again.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[1].message, "I love the weather again.");
}

/* Single publish. Alice timeline request should not return any of Bob's posts */
TEST(Data, Test8) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Bob", "Hello.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline.size(), 0u);
}

/* Single publish. Bob timeline request should return all of Bob's posts */
TEST(Data, Test9) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Bob", "Hello.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Bob");

    EXPECT_EQ(t_timeline.size(), 1u);
}

/* Single publish. Bob timeline request should return posts owned by Bob */
TEST(Data, Test10) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Bob", "Hello.", t_time);
    std::vector<Entry> t_timeline = t_data.timeline("Bob");

    EXPECT_EQ(t_timeline[0].user, "Bob");
}

/* Multiple user publish. Bob timeline request should return posts owned by Bob */
TEST(Data, Test11) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    t_data.publish("Bob", "Hello.", t_time);
    t_data.publish("Alice", "I love the weather again.", t_time);

    std::vector<Entry> t_timeline = t_data.timeline("Bob");

    EXPECT_EQ(t_timeline.size(), 1u);
}

/* Multiple user publish. Alice timeline request should return posts owned by Alice */
TEST(Data, Test12) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time);
    t_data.publish("Bob", "Hello.", t_time);
    t_data.publish("Alice", "I love the weather again.", t_time);

    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline.size(), 2u);
}

/* Single publish. Alice timeline request should ordered from youngest to oldest */
TEST(Data, Test13) {
    Data t_data;
    std::time_t t_time = std::time(nullptr);

    t_data.publish("Alice", "I love the weather today.", t_time-2);
    t_data.publish("Alice", "I love the weather again.", t_time);

    std::vector<Entry> t_timeline = t_data.timeline("Alice");

    EXPECT_EQ(t_timeline[0].message, "I love the weather again.");
}
