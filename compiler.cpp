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
    nextChar();
    nextToken();
}

char Compiler::nextChar(){
    ch = sourceFile.get();
    if (sourceFile.eof()){
        ch = END_OF_FILE;
        return ch;
    }
    while (ch == '\n' || ch == ' ') {
        listingFile << ch;
        (ch == '\n') ? lineNo += 1 : lineNo;

        ch = sourceFile.get();
        if (sourceFile.eof()){
            ch = END_OF_FILE;
            return ch;
        }
    }
    return ch;
}

string Compiler::nextToken(){
    listingFile << "ermmm";
    return "test";
}
