#include "datainterface.h"
#include "subsinterface.h"
#include "command.h"
#include "followcmdhandle.h"

FollowCmdHandle::FollowCmdHandle(DataInterface * _data, SubsInterface * _subs) : CmdHandleInterface(_data,_subs) {}

std::vector<std::string> FollowCmdHandle::handle(const Command &command) {
    subs->follow(command.user,command.message);
    return std::vector<std::string>();
}
