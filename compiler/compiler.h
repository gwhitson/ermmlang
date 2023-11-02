#ifndef COMPILER_H
#define COMPILER_H

#include <fstream>
#include <iostream>

using namespace std;

const char END_OF_FILE = '$';
const string S_END_OF_FILE = "$";

enum storeTypes {INTEGER, BOOLEAN, PROG_NAME, CHAR};
enum modes {VARIABLE, CONSTANT};
enum allocation {YES, NO};

/*class SymbolTableEntry{
    public:
        SymbolTableEntry(string in, storetypes st, modes m, string v, allocation a, int u){
    
        }
}*/

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
};

#endif
