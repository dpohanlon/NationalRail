#include "ClusterParser.h"

ClusterParser::ClusterParser(std::string filename)
{
    parseFile(filename);
}

void ClusterParser::parseLine(std::string l)
{
    clusters.push_back(parseCluster(l));
}

std::unique_ptr<ClusterRecord> ClusterParser::parseCluster(std::string f)
{
    std::unique_ptr<ClusterRecord> record(new ClusterRecord());

    record->update_marker = f.substr(0, 1);
    record->cluster_id    = f.substr(1, 4);
    record->cluster_nlc   = f.substr(5, 4);
    record->end_date      = f.substr(9, 8);
    record->start_date    = f.substr(17, 8);

    return record;
}
