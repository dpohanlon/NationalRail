#include "MSNParser.h"

MSNParser::MSNParser(std::string filename)
{
    parseFile(filename);
}

void MSNParser::parseLine(std::string l)
{
    switch(l[0]){
        case 'A':
            switch(l[30]){
                case 'F':
                    parseHeader(l);
                    break;
                default:
                    stations.push_back(parseStation(l));
                    break;
            }
            break;
    }
}

void MSNParser::parseHeader(std::string h)
{
    std::string type    = h.substr(0, 1);
    std::string version = h.substr(41, 7);
    std::string dateMod = h.substr(48, 8);
    std::string timeMod = h.substr(57, 8);
    std::string verNum  = h.substr(68, 2);
}

std::unique_ptr<MasterStationRecord> MSNParser::parseStation(std::string l)
{
    std::unique_ptr<MasterStationRecord> station(new MasterStationRecord());

    station->type       = l.substr(0, 1);
    station->name       = l.substr(5, 30);
    station->cate       = atoi(l.substr(35, 1).c_str());
    station->tiploc     = l.substr(36, 7);
    station->subAlpha   = l.substr(43, 3);
    station->alpha      = l.substr(49, 3);
    station->easting    = atoi(l.substr(52, 5).c_str());
    station->estimated  = l.substr(57, 1) == "E" ? true : false;
    station->northing   = atoi(l.substr(58, 5).c_str());
    station->changeTime = atoi(l.substr(63, 2).c_str());
    station->footnote   = atoi(l.substr(65, 2).c_str());
    station->region     = atoi(l.substr(78, 3).c_str());

    return station;
}
