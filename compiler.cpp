// starting to build a compiler, we will see how far I take this

#include <compiler.h>
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
    //nextChar();
    string token = nextToken();
    listingFile << token << endl;
}

char Compiler::nextChar(){
    ch = sourceFile.get();
    if (sourceFile.eof()){
        ch = END_OF_FILE;
        return ch;
    }
    return ch;
}

string Compiler::nextToken(){
    listingFile << "ermmm" << endl;
    token = "";
    char ch = nextChar();
    while (token == ""){
        while (!isWhitespace(ch)){
            token += ch;
            ch = nextChar();
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
