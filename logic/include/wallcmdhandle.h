#ifndef WALLCMDHANDLE_H
#define WALLCMDHANDLE_H

#include "cmdhandleinterface.h"

class WallCmdHandle : public CmdHandleInterface {
public:
    WallCmdHandle(DataInterface * _data, SubsInterface * _subs);

    std::vector<std::string> handle(const Command &command) override;

};

#endif // WALLCMDHANDLE_H
