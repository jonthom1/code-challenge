#include <algorithm>
#include <memory>

#include "entry.h"
#include "data.h"

Data::~Data() {
    auto del = [](const Entry* n) { delete n; };
    auto sel = [&](auto n) {
        std::for_each(n.second.begin(),n.second.end(),del);
    };

    //Cleanup memory
    std::for_each(all_tl.begin(),all_tl.end(),sel);
};

void Data::publish(const std::string &user, const std::string &message, std::time_t timestamp) {
    std::unique_ptr<Entry> newEntry(new Entry());
    newEntry->user = user;
    newEntry->message = message;
    newEntry->timestamp = timestamp;

    auto it = all_tl.find(user);

    //If user has a history add to it, otherwise create a new history
    if(it == all_tl.end()) {
        all_tl[user] = std::vector<Entry*>(1,newEntry.release());
    } else {
        it->second.push_back(newEntry.release());
    }
}

std::vector<Entry> Data::timeline(const std::string &user) {
    std::unordered_set<std::string> users;
    users.insert(user);
    return timeline(users);
}

std::vector<Entry> Data::timeline(const std::unordered_set<std::string>& users) {
    std::vector<Entry> ret;

    for( std::string user : users ) {
        auto it = all_tl.find(user);
        if(it != all_tl.end()) {
            auto cpy = [&](const Entry* n) { ret.push_back(*n); };
            std::for_each(it->second.begin(),it->second.end(),cpy);
        }
    }

    auto sortr = [](Entry s1, Entry s2) -> bool { return s2.timestamp < s1.timestamp; };
    std::sort(ret.begin(), ret.end(), sortr);

    return ret;
}
