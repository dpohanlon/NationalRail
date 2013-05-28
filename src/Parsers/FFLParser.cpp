#include "fflParser.h"

fflParser::fflParser(std::string filename)
{
    parseFile(filename);
}

void fflParser::parseLine(std::string l)
{
    switch(l[1]){ // Switch on "RECORD_TYPE"
        case 'F':
            flows.push_back(parseFlow(l));
            break;
        case 'T':
            fares.push_back(parseFare(l));
            break;
    }
}

std::unique_ptr<FlowRecord> fflParser::parseFlow(std::string f)
{
    std::unique_ptr<FlowRecord> record(new FlowRecord());

    record->update_marker    = f.substr(0, 1);
    record->record_type      = f.substr(1, 1);
    record->origin_code      = f.substr(2, 4);
    record->destination_code = f.substr(6, 4);
    record->route_code       = f.substr(10, 5);
    record->status_code      = f.substr(15, 3);
    record->usage_code       = f.substr(18, 1);
    record->direction        = f.substr(19, 1);
    record->end_date         = f.substr(20, 8);
    record->start_date       = f.substr(28, 8);
    record->toc              = f.substr(36, 3);
    record->cross_london_ind = f.substr(39, 1);
    record->publiction_ind   = f.substr(40, 1);
    record->ns_disc_ind      = f.substr(41, 1);
    record->flow_id          = f.substr(42, 7);

    return record;
}

std::unique_ptr<FareRecord> fflParser::parseFare(std::string f)
{
    std::unique_ptr<FareRecord> record(new FareRecord());

    std::string update_marker    = f.substr(0, 1);
    std::string record_type      = f.substr(1, 1);
    std::string flow_id          = f.substr(2, 7);
    std::string ticket_code      = f.substr(9, 3);
    std::string fare             = f.substr(12, 8);
    std::string restriction_code = f.substr(20, 2);

    return record;
}
