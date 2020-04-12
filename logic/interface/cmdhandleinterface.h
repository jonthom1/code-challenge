#ifndef CMDHANDLEINTERFACE_H
#define CMDHANDLEINTERFACE_H

#include <vector>
#include <string>

struct Command;
class DataInterface;
class SubsInterface;

class CmdHandleInterface {
public:
    CmdHandleInterface(DataInterface * _data, SubsInterface * _subs) : data(_data), subs(_subs){}
    virtual ~CmdHandleInterface(){};

    virtual std::vector<std::string> handle(const Command& command) = 0;

protected:
    DataInterface * data; //does not own
    SubsInterface * subs; //does not own
};

#endif // CMDHANDLEINTERFACE_H
