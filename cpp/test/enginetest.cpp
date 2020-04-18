#include <memory>
#include <vector>

#include "gtest/gtest.h"

#include "mockcmdparse.h"
#include "mockcmdhandle.h"

#include "cmdnum.h"
#include "engine.h"

TEST(Engine, Test1) {
    std::unique_ptr<MockCmdParse> tp_cp(new MockCmdParse());
    std::vector<CmdHandleInterface*> t_hndlv;

    Engine t_eng(tp_cp.get(), t_hndlv);

    std::vector<std::string> res = t_eng.process("Alice");

    EXPECT_EQ(tp_cp->pcmd, "Alice");
}

TEST(Engine, Test2) {
    std::unique_ptr<MockCmdParse> tp_cp(new MockCmdParse());
    std::unique_ptr<MockCmdHandle> tp_ch1(new MockCmdHandle(nullptr,nullptr));
    std::unique_ptr<MockCmdHandle> tp_ch2(new MockCmdHandle(nullptr,nullptr));
    std::unique_ptr<MockCmdHandle> tp_ch3(new MockCmdHandle(nullptr,nullptr));
    std::unique_ptr<MockCmdHandle> tp_ch4(new MockCmdHandle(nullptr,nullptr));

    std::vector<CmdHandleInterface*> t_hndlv;
    t_hndlv.push_back(tp_ch1.get());
    t_hndlv.push_back(tp_ch2.get());
    t_hndlv.push_back(tp_ch3.get());
    t_hndlv.push_back(tp_ch4.get());

    Engine t_eng(tp_cp.get(), t_hndlv);

    std::vector<std::string> res = t_eng.process("Alice");

    EXPECT_EQ(tp_ch2->hndl_cc, 1);
}

