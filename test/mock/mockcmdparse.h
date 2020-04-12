#ifndef MOCKCMDPARSE_H
#define MOCKCMDPARSE_H

#include <string>
#include "command.h"
#include "cmdnum.h"

#include "cmdparseinterface.h"



class MockCmdParse : public CmdParseInterface {
public:
    MockCmdParse() : CmdParseInterface(), pcmd("") {}

    Command parse(const std::string &input) override {
        pcmd = input;
        return {TIMELINE, "", ""};
    }

    std::string pcmd;
};

#endif // MOCKCMDPARSE_H
