#include <sstream>

#include "entry.h"
#include "utilfunc.h"

std::vector<std::string> formatEntries(const std::vector<Entry>& entries, bool withName) {
    std::vector<std::string> ret;

    for( Entry e : entries ) {
        std::stringstream res;

        if(withName) res << e.user << " - ";

        res << e.message << " (" << e.timediff << ")";

        ret.push_back(res.str());
    }

    return ret;
}

void formatTimeDiff(std::vector<Entry>& entries) {
    for( Entry& e : entries ) {

        int seconds = std::difftime(std::time(nullptr), e.timestamp);

        int min = seconds/60;
        int hours = min/60;

        std::stringstream res;

        if(hours > 0) hours == 1 ? res << hours << " hour ago" : res << hours << " hours ago";
        else if( min > 0) min == 1 ? res << min << " minute ago" : res << min << " minutes ago";
        else seconds == 1 ? res << seconds << " second ago" : res << seconds << " seconds ago";

        e.timediff = res.str();
    }
}
