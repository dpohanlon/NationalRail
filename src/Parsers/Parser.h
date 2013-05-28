#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <string>

class Parser
{
protected:
    void parseFile(std::string filename);
private:
    virtual void parseLine(std::string l) = 0;
};

#endif
