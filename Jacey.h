#ifndef JACEY_JACEY_H
#define JACEY_JACEY_H

#include <string>
#include <fstream>
using namespace std;

class Jacey {
public:
    Jacey();
    ~Jacey();

    bool Assemble(ifstream &infile, ofstream &outfile);
};


#endif //JACEY_JACEY_H
