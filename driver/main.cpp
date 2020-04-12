#include <iostream>
#include <string>
#include <vector>

#include "engine.h"
#include "logic.h"

int main() {
    Logic logic;

    std::string input;
    std::cout << "> ";
    std::getline(std::cin, input);

    while(input != "exit") {
        std::vector<std::string> ret = logic.engine()->process(input);

        for(std::string str : ret) {
            std::cout << str << std::endl;
        }

        std::cout << "> ";
        std::getline(std::cin, input);
    }

    return 0;
}
