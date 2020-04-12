#ifndef SUBSINTERFACE_H
#define SUBSINTERFACE_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class SubsInterface {
public:
    virtual ~SubsInterface(){}

    virtual void follow(const std::string& follower, const std::string& followed) = 0;
    virtual std::unordered_set<std::string> followedBy(const std::string& follower) = 0;

};

#endif // SUBSINTERFACE_H
