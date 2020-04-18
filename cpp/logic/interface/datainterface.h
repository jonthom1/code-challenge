#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <string>
#include <ctime>
#include <vector>
#include <unordered_set>

struct Entry;

class DataInterface {
public:
    virtual ~DataInterface() {}

    virtual void publish(const std::string& user, const std::string& message, std::time_t timestamp) = 0;
    virtual std::vector<Entry> timeline(const std::string& user) = 0;
    virtual std::vector<Entry> timeline(const std::unordered_set<std::string>& users) = 0;


};

#endif // DATAINTERFACE_H
