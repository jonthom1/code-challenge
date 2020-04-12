#include "subs.h"

void Subs::follow(const std::string &follower, const std::string &followed) {
    auto f_it = all_subs.find(follower);

    //If follower has no subs create new list
    //If list exists, add to list
    if(f_it == all_subs.end()) {
        std::unordered_set<std::string> nset;
        nset.insert(followed);
        all_subs[follower] = nset;
    } else {
        f_it->second.insert(followed);
    }
}

std::unordered_set<std::string> Subs::followedBy(const std::string &follower) {
    std::unordered_set<std::string> ret;

    //Lookup users that the follower has subscribed
    auto f_it = all_subs.find(follower);
    if ( f_it != all_subs.end()) {
        ret = f_it->second;
    }

    //Add follower to list -- all users follow themselves
    ret.insert(follower);
    return ret;
}
