#ifndef PUBLISHCMDHANDLE_H
#define PUBLISHCMDHANDLE_H

#include "cmdhandleinterface.h"

class PublishCmdHandle : public CmdHandleInterface {
public:
    PublishCmdHandle(DataInterface * _data, SubsInterface * _subs);

    std::vector<std::string> handle(const Command &command) override;

};

#endif // PUBLISHCMDHANDLE_H
