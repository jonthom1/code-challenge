#ifndef UTILFUNC_H
#define UTILFUNC_H

#include <vector>
#include <string>

class Entry;

std::vector<std::string> formatEntries(const std::vector<Entry>& entries, bool withName = false);
void formatTimeDiff(std::vector<Entry> &entries);

#endif // UTILFUNC_H
