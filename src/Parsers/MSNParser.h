#ifndef MSNPARSER_H
#define MSNPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Parser.h"

#include "../Records/MasterStationRecord.h"

class MSNParser : public Parser
{

public:
    MSNParser(std::string filename);

    std::vector<std::unique_ptr<MasterStationRecord> > stations;

private:
    void parseLine(std::string l);

    void parseHeader(std::string h);
    std::unique_ptr<MasterStationRecord> parseStation(std::string l);

};

#endif
