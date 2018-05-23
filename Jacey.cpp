#include "Jacey.h"
#include "Utilities.h"

#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;

Jacey::Jacey() = default;
Jacey::~Jacey() = default;

bool Jacey::Assemble(ifstream &infile, ofstream &outfile) {
    string bufferOpcode = "";
    string bufferOperand = "";
    while (!infile.eof()) {
        infile >> bufferOpcode;

        if (IS::InstructionSet.find(bufferOpcode) != IS::InstructionSet.end()) {
            if (bufferOpcode.at(bufferOpcode.length() - 1) == ';') { // 0 operand
                // write map value to outfile
                outfile << IS::InstructionSet.at(bufferOpcode) << bitset<8>(0).to_string()<< endl;
            }
            else { // 1 operand
                outfile << IS::InstructionSet.at(bufferOpcode);

                infile >> bufferOperand;
                if (bufferOperand.at(bufferOperand.length() - 1) == ';') {
                    unsigned long l_op;
                    stringstream ss;
                    ss << hex << bufferOperand.substr(0,bufferOperand.length()-1);
                    ss >> l_op;
                    bitset<8> b_op(l_op);
                    outfile << b_op.to_string() << endl;
                }
                else {
                   // error
                    cout << "Error" << endl;
                    return false;
                }
            }
        }

    }
    return true;
}