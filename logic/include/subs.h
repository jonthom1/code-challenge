#ifndef SUBS_H
#define SUBS_H

#include "subsinterface.h"
class Subs : public SubsInterface {
public:

    void follow(const std::string& follower, const std::string& followed) override;
    std::unordered_set<std::string> followedBy(const std::string& follower) override;


private:
    std::unordered_map<std::string, std::unordered_set<std::string>> all_subs;
};

#endif // SUBS_H
