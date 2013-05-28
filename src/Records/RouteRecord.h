#ifndef ROUTERECORD_H
#define ROUTERECORD_H

#include <string>
#include <vector>

class BSRecord
{
public:
    BSRecord(void);

    std::string id;
    std::string transaction_type;
    std::string train_uid;
    std::string date_from;
    std::string date_to;
    std::string days_run;
    std::string bank_holiday;
    std::string train_status;
    std::string train_category;
    std::string train_id;
    std::string headcode;
    std::string course_indicator;
    std::string train_service_code;
    std::string portion_id;
    std::string power_type;
    std::string timing_load;
    std::string speed;
    std::string operating_chars;
    std::string train_class;
    std::string sleepers;
    std::string reservations;
    std::string connection_ind;
    std::string catering_code;
    std::string service_branding;
    std::string spare;
    std::string stp_ind;
};

class BXRecord
{
public:
    BXRecord(void);

    std::string id;
    std::string traction_class;
    std::string uic_code;
    std::string atoc_code;
    std::string timetable_code;
    std::string reserved_1;
    std::string reserved_2;
};

class LORecord
{
public:
    LORecord(void);

    std::string id;
    std::string tiploc;
    std::string loc_suffix;
    std::string sched_depart;
    std::string pub_depart;
    std::string platform;
    std::string line;
    std::string eng_allow;
    std::string path_allow;
    std::string activity;
    std::string perf_allow;
};

class LIRecord
{
public:
    LIRecord(void);

    std::string id;
    std::string tiploc;
    std::string loc_suffix;
    std::string sched_arriv;
    std::string sched_dep;
    std::string sched_pass;
    std::string pub_arriv;
    std::string pub_dep;
    std::string platform;
    std::string line;
    std::string path;
    std::string activity;
    std::string eng_allow;
    std::string path_allow;
    std::string perf_allow;
};

class LTRecord
{
public:
    LTRecord(void);

    std::string id;
    std::string tiploc;
    std::string loc_suffix;
    std::string sched_arriv;
    std::string pub_arriv;
    std::string platform;
    std::string path;
    std::string activity;
};

class RouteRecord
{
public:
    RouteRecord(void);

    std::unique_ptr<BSRecord> bs;
    std::unique_ptr<BXRecord> bx;

    std::unique_ptr<LORecord>               lo;
    std::vector<std::unique_ptr<LIRecord> > li;
    std::unique_ptr<LTRecord>               lt;
};

#endif
