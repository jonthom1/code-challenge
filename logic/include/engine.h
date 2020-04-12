#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include <string>
#include <unordered_map>

class CmdParseInterface;
class CmdHandleInterface;

class Engine {
public:
    Engine(CmdParseInterface * _cmdp, const std::vector<CmdHandleInterface*>& _handlers);

    std::vector<std::string> process(const std::string& input);

private:
    CmdParseInterface * cmdp;   //Does not own
    std::vector<CmdHandleInterface*> handlers; //Does not own

    std::unordered_map<int, CmdHandleInterface*> hndl_map;//Does not own
};

#endif // ENGINE_H
