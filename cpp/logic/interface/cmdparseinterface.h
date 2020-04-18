#ifndef CMDPARSEINTERFACE_H
#define CMDPARSEINTERFACE_H

#include <string>

struct Command;

class CmdParseInterface {
public:
    virtual ~CmdParseInterface() {}

    virtual Command parse(const std::string& input) = 0;
};

#endif // CMDPARSEINTERFACE_H
