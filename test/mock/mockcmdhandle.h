#ifndef MOCKCMDHANDLE_H
#define MOCKCMDHANDLE_H

#include "command.h"
#include "cmdhandleinterface.h"

class MockCmdHandle : public CmdHandleInterface {
public:
    MockCmdHandle(DataInterface * _data, SubsInterface * _subs) : CmdHandleInterface(_data,_subs), hndl_cc(0){}

    std::vector<std::string> handle(const Command& command) {
        ++hndl_cc;
        return std::vector<std::string>();
    }

    int hndl_cc;
};

#endif // MOCKCMDHANDLE_H
