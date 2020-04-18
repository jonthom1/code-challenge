#include "datainterface.h"
#include "command.h"
#include "publishcmdhandle.h"

PublishCmdHandle::PublishCmdHandle(DataInterface * _data, SubsInterface *_subs) : CmdHandleInterface(_data, _subs) {}

std::vector<std::string> PublishCmdHandle::handle(const Command &command) {
    data->publish(command.user,command.message,std::time(nullptr));
    return std::vector<std::string>();
}
