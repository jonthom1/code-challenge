#ifndef MOCKDATA_H
#define MOCKDATA_H

#include <vector>

#include "entry.h"
#include "datainterface.h"

class MockData : public DataInterface {
public:
    MockData() : DataInterface(), pub_cc(0) {}

    void publish(const std::string& user, const std::string& message, std::time_t timestamp) override {
        ++pub_cc;
    }

    std::vector<Entry> timeline(const std::string& user) override {
        Entry ent1 = {"Alice","I love the weather today.",std::time(nullptr),""};
        if(user == "Alice") return std::vector<Entry>(1, ent1);

        return std::vector<Entry>();
    };

    std::vector<Entry> timeline(const std::unordered_set<std::string> &users) override {
        for( std::string user : users ) {
            Entry ent1 = {"Alice","I love the weather today.",std::time(nullptr),""};
            if(user == "Alice") return std::vector<Entry>(1, ent1);
        }

        return std::vector<Entry>();
    }

    int pub_cc;
};

#endif // MOCKDATA_H
