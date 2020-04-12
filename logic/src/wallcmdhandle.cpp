#include "utilfunc.h"
#include "entry.h"
#include "datainterface.h"
#include "subsinterface.h"
#include "command.h"
#include "wallcmdhandle.h"

WallCmdHandle::WallCmdHandle(DataInterface * _data, SubsInterface * _subs) : CmdHandleInterface(_data,_subs) {}

std::vector<std::string> WallCmdHandle::handle(const Command &command) {
    std::unordered_set<std::string> usubs = subs->followedBy(command.user);
    std::vector<Entry> entries = data->timeline(usubs);

    formatTimeDiff(entries);
    bool withName = true;
    return formatEntries(entries, withName);
}
