#ifndef LOCRECORD_H
#define LOCRECORD_H

#include <string>

class StationRecord
{
public:
    StationRecord(void);

    std::string update_marker;
    std::string record_type;
    int         uic_code;
    int         end_date;
    int         start_date;
    int         quote_date;
    int         admin_area_code;
    int         nlc_code;
    std::string description;
    std::string crs_code;
    std::string resv_code;
    std::string ers_country;
    std::string ers_code;
    std::string fare_group;
    std::string country;
    std::string pte_code;
    std::string zone_no;
    std::string zone_ind;
    std::string region;
    std::string hierarchy;
    std::string cc_dest_out;
    std::string cc_dest_rtn;
    std::string atb_desc_out;
    std::string atb_desc_rtn;
    std::string special_facilities;
    std::string lul_direction_ind;
    std::string lul_uts_mode;
    std::string lul_zone_1;
    std::string lul_zone_2;
    std::string lul_zone_3;
    std::string lul_zone_4;
    std::string lul_zone_5;
    std::string lul_zone_6;
    std::string lul_uts_london_stn;
    std::string uts_code;
    std::string uts_a_code;
    std::string uts_ptr_bias;
    std::string uts_offset;
    std::string uts_north;
    std::string uts_east;
    std::string uts_south;
    std::string uts_west;
};

class AssocStationRecord
{
public:
    AssocStationRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string uic_code;
    std::string end_date;
    std::string assoc_uic_code;
    std::string assoc_crs_code;
};

class RailGeogRecord
{
public:
    RailGeogRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string uic_code;
    std::string railcard_code;
    std::string end_date;
};

class TTGroupRecord
{
public:
    TTGroupRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string group_uic_code;
    std::string end_date;
    std::string start_date;
    std::string quote_date;
    std::string description;
    std::string ers_country;
    std::string ers_code;
};

class GroupMembersRecord
{
public:
    GroupMembersRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string group_uic_code;
    std::string end_date;
    std::string member_uic_code;
    std::string member_crs_code;
};

class SynonymRecord
{
public:
    SynonymRecord(void);

    std::string update_marker;
    std::string record_type;
    std::string uic_code;
    std::string end_date;
    std::string start_date;
    std::string description;
};

#endif
