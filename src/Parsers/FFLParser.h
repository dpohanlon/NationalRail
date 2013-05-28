#ifndef FFLPARSER_H
#define FFLPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Parser.h"

#include "../Records/FflRecord.h"

class fflParser : public Parser
{
public:
    fflParser(std::string filename);

    std::vector<std::unique_ptr<FlowRecord> > flows;
    std::vector<std::unique_ptr<FareRecord> > fares;

private:

    void parseLine(std::string l);
    std::unique_ptr<FareRecord> parseFare(std::string f);
    std::unique_ptr<FlowRecord> parseFlow(std::string f);
};

#endif
