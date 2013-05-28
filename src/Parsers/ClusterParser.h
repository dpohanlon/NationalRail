#ifndef CLUSTERPARSER_H
#define CLUSTERPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Parser.h"

#include "../Records/ClusterRecord.h"

class ClusterParser : public Parser
{
public:

    ClusterParser(std::string filename);

    std::vector<std::unique_ptr<ClusterRecord> > clusters;

private:

    void parseLine(std::string l);
    std::unique_ptr<ClusterRecord> parseCluster(std::string f);

};

#endif
