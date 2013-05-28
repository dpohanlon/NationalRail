#ifndef FFLRECORD_H
#define FFLRECORD_H

#include <string>

class FlowRecord
{
public:
    FlowRecord(void);
    
    std::string update_marker;
    std::string record_type;
    std::string origin_code;
    std::string destination_code;
    std::string route_code;
    std::string status_code;
    std::string usage_code;
    std::string direction;
    std::string end_date;
    std::string start_date;
    std::string toc;
    std::string cross_london_ind;
    std::string publiction_ind;
    std::string ns_disc_ind;
    std::string flow_id;
};

class FareRecord
{
public:
    FareRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string flow_id;
    std::string ticket_code;
    std::string fare;
    std::string restriction_code;
};

#endif
