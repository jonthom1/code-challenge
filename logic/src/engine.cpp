#include "command.h"
#include "cmdnum.h"

#include "cmdhandleinterface.h"
#include "cmdparseinterface.h"

#include "engine.h"

Engine::Engine(CmdParseInterface * _cmdp, const std::vector<CmdHandleInterface*>& _handlers) : cmdp(_cmdp){
    size_t s = _handlers.size();

    //Build command dispatch table
    if(s > 0) hndl_map[PUBLISH] = _handlers[0];
    if(s > 1) hndl_map[TIMELINE] = _handlers[1];
    if(s > 2) hndl_map[FOLLOW] = _handlers[2];
    if(s > 3) hndl_map[WALL] = _handlers[3];
}

std::vector<std::string> Engine::process(const std::string &input) {
    //Transform input command to command ID
    Command command = cmdp->parse(input);

    std::vector<std::string> ret;

    auto it = hndl_map.find(command.cmd);

    //Find command handle by ID and execute
    if(it != hndl_map.end()) {
        ret = it->second->handle(command);
    }

    return ret;
}
