#ifndef ROUTEPARSER_H
#define ROUTEPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Parser.h"

#include "../Records/RouteRecord.h"

class RouteParser : public Parser
{
public:
    RouteParser(std::string filename);

    std::vector<std::unique_ptr<RouteRecord> > routes;

private:
    void parseLine(std::string l);

    std::unique_ptr<BSRecord> parseBS(std::string f);
    std::unique_ptr<BXRecord> parseBX(std::string f);

    std::unique_ptr<LORecord> parseLO(std::string f);
    std::unique_ptr<LIRecord> parseLI(std::string f);
    std::unique_ptr<LTRecord> parseLT(std::string f);

    std::unique_ptr<RouteRecord> newRoute(std::unique_ptr<BSRecord> b);

};

#endif
