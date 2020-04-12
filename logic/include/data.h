#ifndef DATA_H
#define DATA_H

#include <unordered_map>

#include "datainterface.h"

struct Entry;

class Data : public DataInterface {
public:
    ~Data();

    void publish(const std::string& user, const std::string& message, std::time_t timestamp) override;
    std::vector<Entry> timeline(const std::string& user) override;
    std::vector<Entry> timeline(const std::unordered_set<std::string>& users) override;

private:
    std::unordered_map<std::string, std::vector<Entry*>> all_tl;
};

#endif // DATA_H
