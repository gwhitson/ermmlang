// starting to build a compiler, we will see how far I take this

#include "compiler.h"
#include <cctype>

//Constructor
Compiler::Compiler(char **argv){
        sourceFile.open(argv[1]);
        listingFile.open(argv[2]);
        objectFile.open(argv[3]);
}

//Destructor
Compiler::~Compiler(){
    sourceFile.close();
    listingFile.close();
    objectFile.close();
}

void Compiler::parser(){
    lineNo++;
    string ltoken = nextToken();
    while (ltoken != S_END_OF_FILE){
        listingFile <<  /*" - token: " << */ltoken << endl;
        ltoken = nextToken();
    }
}

char Compiler::nextChar(){
    ch = sourceFile.get();
    if (sourceFile.eof()){
        ch = END_OF_FILE;
        return ch;
    }
    //listingFile << " -- char: " << ch << endl;
    return ch;
}

string Compiler::nextToken(){
    token = "";
    while (token == ""){
        char x = nextChar();
        if (!isWhitespace(x)){
            while (!isWhitespace(x)){
                token += x;
                x = nextChar();
            }
        } else if (x == END_OF_FILE) {
            token = S_END_OF_FILE;
        }
    }
    return token;
}

bool Compiler::isWhitespace(char token){
    if (token == ' ' || token == '\n' || token == '\t' || token == END_OF_FILE){
        return true;
    }
    return false;
}
