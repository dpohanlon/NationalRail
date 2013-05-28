#include "Parser.h"

void Parser::parseFile(std::string filename) // parse headers?
{
    std::ifstream file;

    file.open(filename.c_str());

    if(file.is_open()){
        std::string line;

        while(std::getline(file, line)){
            parseLine(line);
        }
    }
    file.close();
}
