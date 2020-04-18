#include <memory>
#include "gtest/gtest.h"

#include "cmdnum.h"
#include "command.h"
#include "publishcmdhandle.h"

#include "mockdata.h"

TEST(publish, Test1) {
    std::unique_ptr<MockData> tp_data(new MockData());

    PublishCmdHandle t_pcmd(tp_data.get(), nullptr);
    Command t_cmd = {PUBLISH, "Alice", "I love the weather today."};

    EXPECT_TRUE(t_pcmd.handle(t_cmd).empty());
}

TEST(publish, Test2) {
    std::unique_ptr<MockData> tp_data(new MockData());

    PublishCmdHandle t_pcmd(tp_data.get(), nullptr);
    Command t_cmd = {PUBLISH, "Alice", "I love the weather today."};

    t_pcmd.handle(t_cmd);

    EXPECT_EQ(tp_data->pub_cc, 1);
}

TEST(publish, Test3) {
    std::unique_ptr<MockData> tp_data(new MockData());

    PublishCmdHandle t_pcmd(tp_data.get(), nullptr);
    Command t_cmd = {PUBLISH, "Alice", "I love the weather today."};

    t_pcmd.handle(t_cmd);
    t_pcmd.handle(t_cmd);
    t_pcmd.handle(t_cmd);
    t_pcmd.handle(t_cmd);

    EXPECT_EQ(tp_data->pub_cc, 4);
}
