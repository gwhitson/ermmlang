#ifndef COMPILER_H
#define COMPILER_H

#include <string.h>
#include <array>
#include <fstream>
#include <algorithm>
#include <iostream>

using std::string;
using std::ifstream;
using std::ofstream;
using std::array;
using std::cout;

const char END_OF_FILE = '$';
const string S_END_OF_FILE = "$";

enum storeTypes {INTEGER, BOOLEAN, PROG_NAME, CHAR};
enum modes {VARIABLE, CONSTANT};
enum allocation {YES, NO};

class SymbolTableEntry{
    public:
        SymbolTableEntry(string in, storeTypes st, modes m, string v, allocation a, int u) {
            setInternalName(in);
            setDataType(st);
            setMode(m);
            setValue(v);
            setAlloc(a);
            setUnits(u);
        }    

        string getInternalName() const {
            return internalName;
        }

        storeTypes getDataType() const {
            return dataType;
        }

        modes getMode() const {
            return mode;
        }

        string getValue() const {
            return value;
        }

        allocation getAlloc() const {
            return alloc;
        }

        int getUnits() const {
            return units;
        }

        void setInternalName(string s) {
            internalName = s;
        }

        void setDataType(storeTypes st) {
            dataType = st;
        }

        void setMode(modes m) {
            mode = m;
        }

        void setValue(string s) {
            value = s;
        }

        void setAlloc(allocation a) {
            alloc = a;
        }

        void setUnits(int i) {
            units = i;
        }

    private:
        string internalName;
        storeTypes dataType;
        modes mode;
        string value;
        allocation alloc;
        int units;
};

class Compiler {
    public:
        Compiler(char **argv);
        ~Compiler();

        void parser();
        
        char nextChar();
        string nextToken();

        bool isWhitespace(char x);
        bool isKeyword(string x);
        bool isEOF(string x);
        bool isEOF(char x);
        void processError();
    private:
        ifstream sourceFile;
        ofstream listingFile;
        ofstream objectFile;
        string token;
        char ch;
        uint errorCount = 0;
        uint lineNo = 0;
        const array<string, 8> operations {"+", "-", "/", "*", "//", "**", "=", ";"};
};

#endif
