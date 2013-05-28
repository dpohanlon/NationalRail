#include "locParser.h"

locParser::locParser(std::string filename)
{
    parseFile(filename);
}

void locParser::parseLine(std::string l)
{
    switch(l[1]){ // Switch on "RECORD_TYPE"
        case 'L':
            stations.push_back(parseStation(l));
            break;
        case 'A':
            assocStations.push_back(parseAssocStation(l));
            break;
        case 'R':
            railGeogs.push_back(parseRailGeog(l));
            break;
        case 'G':
            tTgroups.push_back(parseTtgroup(l));
            break;
        case 'M':
            groupMembers.push_back(parseGroupMembers(l));
            break;
        case 'S':
            synonyms.push_back(parseSynonym(l));
            break;
    }
}

std::unique_ptr<StationRecord> locParser::parseStation(std::string s)
{
    std::unique_ptr<StationRecord> record(new StationRecord());

    record->update_marker      = s.substr(0, 1);
    record->record_type        = s.substr(1, 1);
    record->uic_code           = atoi(s.substr(2, 7).c_str());
    record->end_date           = atoi(s.substr(9, 8).c_str());
    record->start_date         = atoi(s.substr(17, 8).c_str());
    record->quote_date         = atoi(s.substr(25, 8).c_str());
    record->admin_area_code    = atoi(s.substr(33, 3).c_str());
    record->nlc_code           = atoi(s.substr(36, 4).c_str());
    record->description        = s.substr(40, 16);
    record->crs_code           = s.substr(56, 3);
    record->resv_code          = s.substr(59, 5);
    record->ers_country        = s.substr(64, 2);
    record->ers_code           = s.substr(66, 3);
    record->fare_group         = s.substr(69, 6);
    record->country            = s.substr(75, 2);
    record->pte_code           = s.substr(77, 2);
    record->zone_no            = s.substr(79, 4);
    record->zone_ind           = s.substr(83, 2);
    record->region             = s.substr(85, 1);
    record->hierarchy          = s.substr(86, 1);
    record->cc_dest_out        = s.substr(87, 41);
    record->cc_dest_rtn        = s.substr(128, 16);
    record->atb_desc_out       = s.substr(144, 60);
    record->atb_desc_rtn       = s.substr(204, 30);
    record->special_facilities = s.substr(234, 26);
    record->lul_direction_ind  = s.substr(260, 1);
    record->lul_uts_mode       = s.substr(261, 1);
    record->lul_zone_1         = s.substr(262, 1);
    record->lul_zone_2         = s.substr(263, 1);
    record->lul_zone_3         = s.substr(264, 1);
    record->lul_zone_4         = s.substr(265, 1);
    record->lul_zone_5         = s.substr(266, 1);
    record->lul_zone_6         = s.substr(267, 1);
    record->lul_uts_london_stn = s.substr(268, 1);
    record->uts_code           = s.substr(269, 3);
    record->uts_a_code         = s.substr(272, 3);
    record->uts_ptr_bias       = s.substr(275, 1);
    record->uts_offset         = s.substr(276, 1);
    record->uts_north          = s.substr(277, 3);
    record->uts_east           = s.substr(280, 3);
    record->uts_south          = s.substr(283, 3);
    record->uts_west           = s.substr(286, 3);

    return record;
}

std::unique_ptr<AssocStationRecord> locParser::parseAssocStation(std::string s)
{
    std::unique_ptr<AssocStationRecord> record(new AssocStationRecord());

    record->update_marker  = s.substr(0, 1);
    record->record_type    = s.substr(1, 1);
    record->uic_code       = s.substr(2, 7);
    record->end_date       = s.substr(9, 8);
    record->assoc_uic_code = s.substr(17, 7);
    record->assoc_crs_code = s.substr(24, 3);

    return record;
}

std::unique_ptr<RailGeogRecord> locParser::parseRailGeog(std::string r)
{
    std::unique_ptr<RailGeogRecord> record(new RailGeogRecord());

    record->update_marker = r.substr(0, 1);
    record->record_type   = r.substr(1, 1);
    record->uic_code      = r.substr(2, 7);
    record->railcard_code = r.substr(9, 3);
    record->end_date      = r.substr(12, 8);

    return record;
}

std::unique_ptr<TTGroupRecord> locParser::parseTtgroup(std::string g)
{
    std::unique_ptr<TTGroupRecord> record(new TTGroupRecord());

    record->update_marker  = g.substr(0, 1);
    record->record_type    = g.substr(1, 1);
    record->group_uic_code = g.substr(2, 7);
    record->end_date       = g.substr(9, 8);
    record->start_date     = g.substr(17, 8);
    record->quote_date     = g.substr(25, 8);
    record->description    = g.substr(33, 16);
    record->ers_country    = g.substr(49, 2);
    record->ers_code       = g.substr(51, 3);

    return record;
}

std::unique_ptr<GroupMembersRecord> locParser::parseGroupMembers(std::string g)
{
    std::unique_ptr<GroupMembersRecord> record(new GroupMembersRecord());

    record->update_marker   = g.substr(0, 1);
    record->record_type     = g.substr(1, 1);
    record->group_uic_code  = g.substr(2, 7);
    record->end_date        = g.substr(9, 8);
    record->member_uic_code = g.substr(17, 7);
    record->member_crs_code = g.substr(24, 3);

    return record;
}

std::unique_ptr<SynonymRecord> locParser::parseSynonym(std::string s)
{
    std::unique_ptr<SynonymRecord> record( new SynonymRecord());

    record->update_marker = s.substr(0, 1);
    record->record_type   = s.substr(1, 1);
    record->uic_code      = s.substr(2, 7);
    record->end_date      = s.substr(9, 8);
    record->start_date    = s.substr(17, 8);
    record->description   = s.substr(25, 16);

    return record;
}
