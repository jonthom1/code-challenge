#include <vector>
#include <string>

#include "cmdnum.h"
#include "command.h"
#include "cmdparse.h"

CmdParse::CmdParse() {
    cmdmap["->"] = PUBLISH;
    cmdmap[""] = TIMELINE;
    cmdmap["follow"] = FOLLOW;
    cmdmap["wall"] = WALL;
}

Command CmdParse::parse(const std::string &input) {
    std::vector<std::string> split = splitOnSpace(input);

    Command ret = {
        mapCmd( split.size() > 1 ? split[1] : "" )
        , split.size() > 0 ? split[0] : ""
        , split.size() > 2 ? split[2] : ""
    };


    return ret;
}

std::vector<std::string> CmdParse::splitOnSpace(const std::string &input) {
    std::vector<std::string> split;
    std::string sec;
    for( char c : input ) {
        if(c == ' ' && split.size() < 2) {
            if( !sec.empty() ) split.push_back(sec);
            sec.clear();
        } else {
            sec += c;
        }
    }

    if( !sec.empty() ) split.push_back(sec);

    return split;
}

int CmdParse::mapCmd(const std::string& scmd) {
    int ret = -1;
    auto it = cmdmap.find(scmd);
    if(it != cmdmap.end()) {
        ret = it->second;
    }

    return ret;
}
