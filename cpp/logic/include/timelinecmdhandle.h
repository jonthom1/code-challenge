#ifndef TIMELINECMDHANDLE_H
#define TIMELINECMDHANDLE_H

#include "cmdhandleinterface.h"

class TimelineCmdHandle : public CmdHandleInterface {
public:
    TimelineCmdHandle(DataInterface * _data, SubsInterface * _subs);

    std::vector<std::string> handle(const Command &command) override;

};


#endif // TIMELINECMDHANDLE_H
