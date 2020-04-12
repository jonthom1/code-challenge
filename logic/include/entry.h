#ifndef ENTRY_H
#define ENTRY_H

#include <string>
#include <ctime>

struct Entry {
    std::string user;
    std::string message;
    std::time_t timestamp;
    std::string timediff;
};

#endif // ENTRY_H
