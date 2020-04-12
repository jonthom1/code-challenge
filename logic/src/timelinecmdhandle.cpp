#include <sstream>
#include "utilfunc.h"
#include "datainterface.h"
#include "command.h"
#include "entry.h"

#include "timelinecmdhandle.h"

TimelineCmdHandle::TimelineCmdHandle(DataInterface * _data, SubsInterface * _subs) : CmdHandleInterface(_data,_subs) {}

std::vector<std::string> TimelineCmdHandle::handle(const Command &command) {
    std::vector<Entry> entries = data->timeline(command.user);
    formatTimeDiff(entries);
    return formatEntries(entries);
}
