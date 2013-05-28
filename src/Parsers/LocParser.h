#ifndef LOCPARSER_H
#define LOCPARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "Parser.h"

#include "../Records/LocRecord.h"

class locParser : public Parser
{

public:

    locParser(std::string filename);

    std::vector<std::unique_ptr<StationRecord> >      stations;
    std::vector<std::unique_ptr<AssocStationRecord> > assocStations;
    std::vector<std::unique_ptr<RailGeogRecord> >     railGeogs;
    std::vector<std::unique_ptr<TTGroupRecord> >      tTgroups;
    std::vector<std::unique_ptr<GroupMembersRecord> > groupMembers;
    std::vector<std::unique_ptr<SynonymRecord> >      synonyms;

private:

    void parseLine(std::string l);

    std::unique_ptr<StationRecord>      parseStation(std::string s);
    std::unique_ptr<AssocStationRecord> parseAssocStation(std::string s);
    std::unique_ptr<RailGeogRecord>     parseRailGeog(std::string r);
    std::unique_ptr<TTGroupRecord>      parseTtgroup(std::string g);
    std::unique_ptr<GroupMembersRecord> parseGroupMembers(std::string g);
    std::unique_ptr<SynonymRecord>      parseSynonym(std::string s);
    
};

#endif
