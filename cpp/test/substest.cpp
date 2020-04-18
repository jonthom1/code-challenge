#include "gtest/gtest.h"

#include "subs.h"

TEST(Subs, Test1) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Chris");

    EXPECT_EQ(t_following.size(), 2u);
}

TEST(Subs, Test2) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Chris");

    EXPECT_NE(t_following.find("Alice"), t_following.end());
}

TEST(Subs, Test3) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Chris");

    EXPECT_EQ(t_following.find("Bob"), t_following.end());
}

TEST(Subs, Test4) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Alice");

    EXPECT_EQ(t_following.size(), 1u);
}

TEST(Subs, Test5) {
    Subs t_subs;

    t_subs.follow("Alice","Chris");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Alice");

    EXPECT_EQ(t_following.size(), 2u);
}

TEST(Subs, Test6) {
    Subs t_subs;

    t_subs.follow("Alice","Chris");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Alice");

    EXPECT_NE(t_following.find("Chris"), t_following.end());
}

TEST(Subs, Test7) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    t_subs.follow("Chris", "Alice");
    t_subs.follow("Chris", "Alice");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Chris");

    EXPECT_EQ(t_following.size(), 2u);
}

TEST(Subs, Test8) {
    Subs t_subs;

    t_subs.follow("Chris", "Alice");
    t_subs.follow("Chris", "Bob");
    std::unordered_set<std::string> t_following = t_subs.followedBy("Chris");

    EXPECT_EQ(t_following.size(), 3u);
}

