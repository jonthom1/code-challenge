#ifndef LOGIC_H
#define LOGIC_H

#include <memory>

class Engine;
class DataInterface;
class SubsInterface;
class CmdParseInterface;
class CmdHandleInterface;

class Logic {
public:
    Logic();
    ~Logic();

    Engine * engine() const;

private:

    DataInterface * data;
    SubsInterface * subs;
    CmdParseInterface * cmdparse;
    CmdHandleInterface * pubcmdh;
    CmdHandleInterface * tlcmdh;
    CmdHandleInterface * flwcmdh;
    CmdHandleInterface * wcmdh;
    Engine * eng;

};

#endif // LOGIC_H
