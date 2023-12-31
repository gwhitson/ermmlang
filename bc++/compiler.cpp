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
    nextChar();
    string ltoken = nextToken();
    while (ltoken != S_END_OF_FILE){
        listingFile <<  ltoken;
        ltoken = nextToken();
    }
}

char Compiler::nextChar(){
    if (static_cast<int>(sourceFile.peek()) == -1){
        ch = END_OF_FILE;
    }else{
        ch = sourceFile.get();
    }
    cout << ch << endl;
    ///listingFile << " -char: " << ch;
    return ch;
}

string Compiler::nextToken(){
    token = "";
    //char ch = nextChar();
    while (token == ""){
        if (ch == END_OF_FILE){
            token = S_END_OF_FILE;
        } else if (isWhitespace(ch)) {
            while (isWhitespace(ch)) {
                token += ch;
                ch = nextChar();
            }
        } else {
            while (!isDelimiter(ch)){
                token += ch;
                ch = nextChar();
            }
        }
    }
    return token;
}

bool Compiler::isDelimiter(char x){
    if (isWhitespace(x) || isEOF(x)){
        return true;
    }
    return false;
}

bool Compiler::isWhitespace(char x){
    if (x == ' ' || x == '\n' || x == '\t'){
        return true;
    }
    return false;
}

/*bool Compiler::isEOF(string x){
    if (x == S_END_OF_FILE){
        return true;
    }
    return false;
}*/

bool Compiler::isEOF(char x){
    if (x == END_OF_FILE){
        return true;
    }
    return false;
}
