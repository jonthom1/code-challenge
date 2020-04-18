#ifndef COMMAND_H
#define COMMAND_H

#include <string>

struct Command {
    int cmd;
    std::string user;
    std::string message;
};

#endif // COMMAND_H
