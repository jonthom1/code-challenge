#include <memory>
#include "gtest/gtest.h"

#include "cmdnum.h"
#include "command.h"
#include "timelinecmdhandle.h"

#include "mockdata.h"

TEST(timeline, Test1) {
    std::unique_ptr<MockData> tp_data(new MockData());

    TimelineCmdHandle t_tlcmd(tp_data.get(), nullptr);
    Command t_cmd = {TIMELINE, "Alice", ""};

    EXPECT_EQ(t_tlcmd.handle(t_cmd).size(), 1u);
}

TEST(timeline, Test2) {
    std::unique_ptr<MockData> tp_data(new MockData());

    TimelineCmdHandle t_tlcmd(tp_data.get(), nullptr);
    Command t_cmd = {TIMELINE, "Alice", ""};

    std::vector<std::string> ret = t_tlcmd.handle(t_cmd);

    EXPECT_EQ(ret[0], "I love the weather today. (0 seconds ago)");
}

