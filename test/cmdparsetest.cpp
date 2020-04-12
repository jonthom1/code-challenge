#include "gtest/gtest.h"

#include "cmdnum.h"
#include "command.h"
#include "cmdparse.h"


TEST(CmdParse, Test1) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice");

    EXPECT_EQ(t_cmd.cmd, TIMELINE);
}

TEST(CmdParse, Test2) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice");

    EXPECT_EQ(t_cmd.user, "Alice");
}

TEST(CmdParse, Test3) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice");

    EXPECT_EQ(t_cmd.message, "");
}

TEST(CmdParse, Test4) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice -> I love the weather today.");

    EXPECT_EQ(t_cmd.message, "I love the weather today.");
}

TEST(CmdParse, Test5) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice -> I love the weather today.");

    EXPECT_EQ(t_cmd.cmd, PUBLISH);
}

TEST(CmdParse, Test6) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Alice -> I love the weather today.");

    EXPECT_EQ(t_cmd.user, "Alice");
}

TEST(CmdParse, Test7) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Bob wall");

    EXPECT_EQ(t_cmd.message, "");
}

TEST(CmdParse, Test8) {
    CmdParse t_cp;

    Command t_cmd = t_cp.parse("Bob -> Hello");

    EXPECT_EQ(t_cmd.message, "Hello");
}
