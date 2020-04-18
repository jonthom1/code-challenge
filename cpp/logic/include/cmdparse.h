#ifndef CMDPARSE_H
#define CMDPARSE_H

#include <vector>
#include <string>
#include <unordered_map>

#include "cmdparseinterface.h"

struct Command;

class CmdParse : public CmdParseInterface {
public:
    CmdParse();

    Command parse(const std::string& input);

private:
    std::unordered_map<std::string, int> cmdmap;

    inline std::vector<std::string> splitOnSpace(const std::string& input);
    inline int mapCmd(const std::string& scmd);
};

#endif // CMDPARSE_H
