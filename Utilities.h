#ifndef JACEY_UTILITIES_H
#define JACEY_UTILITIES_H

#include <string>
#include <map>
using namespace std;

namespace IS {
    map<string, string> const InstructionSet = {
            {"LDA","0001"},
            {"STA","0010"},
            {"ADD;","0011"},
            {"SUB;","0100"},
            {"MBA;","0101"},
            {"JMP","0110"},
            {"JN","0111"},
            {"HLT;","1000"},
            {"LAI","1001"}
    };
}

#endif //JACEY_UTILITIES_H
