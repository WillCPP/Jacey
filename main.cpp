#include "Jacey.h"

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    string fileIn = "";
    string fileOut = "";

    if (argc == 1) {
        fileIn = "program.asm";
        fileOut = "program.je";
    }
    else if (argc == 2) {
        fileIn = argv[1];
        fileOut = "program.je";
    }
    else if (argc == 3) {
        fileIn = argv[1];
        fileOut = argv[2];
    }
    else {
        cout << "Error: Incorrect number of command line arguments." << endl;
        return 1;
    }

    ifstream infile(fileIn);
    if (infile.fail()) {
        cout << "Error: Failed to open input file." << endl;
        return 2;
    }
    ofstream outfile(fileOut);
    if (outfile.fail()) {
        cout << "Error: Failed to open output file." << endl;
        return 3;
    }

    Jacey assembler;
    bool success = assembler.Assemble(infile, outfile);

    if (!success) {
        cout << "Error: Failed to assemble program." << endl;
        return 4;
    }

    infile.close();
    outfile.close();

    return 0;
}