#ifndef FOLLOWCMDHANDLE_H
#define FOLLOWCMDHANDLE_H

#include "cmdhandleinterface.h"

class FollowCmdHandle : public CmdHandleInterface {
public:
    FollowCmdHandle(DataInterface * _data, SubsInterface * _subs);

    std::vector<std::string> handle(const Command &command) override;

};

#endif // FOLLOWCMDHANDLE_H
