#include "RouteParser.h"

RouteParser::RouteParser(std::string filename)
{
    parseFile(filename);
}

void RouteParser::parseLine(std::string l)
{
    switch(l[0]){
        case 'B':
            switch(l[1]){
                case 'S':
                    // HACK: stp_ind = C => blank info (for some reason)
                    if(l[79] != 'C') routes.push_back(newRoute(parseBS(l)));
                    break;
                case 'X':
                    (routes.back())->bx = move(parseBX(l));
                    break;
            }
            break;
        case 'L':
            switch(l[1]){
                case 'O':
                    (routes.back())->lo = move(parseLO(l));
                    break;
                case 'I':
                    (routes.back())->li.push_back(parseLI(l));
                    break;
                case 'T':
                    (routes.back())->lt = move(parseLT(l));
                    break;
            }
            break;
    }
}

std::unique_ptr<RouteRecord> RouteParser::newRoute(std::unique_ptr<BSRecord> b)
{
    std::unique_ptr<RouteRecord> route(new RouteRecord());
    route->bs = move(b);

    return route;
}

std::unique_ptr<BSRecord> RouteParser::parseBS(std::string f)
{
    std::unique_ptr<BSRecord> record(new BSRecord());

    record->id                 = f.substr(0, 2);
    record->transaction_type   = f.substr(2, 1);
    record->train_uid          = f.substr(3, 6);
    record->date_from          = f.substr(9, 6);
    record->date_to            = f.substr(15, 6);
    record->days_run           = f.substr(21, 7);
    record->bank_holiday       = f.substr(28, 1);
    record->train_status       = f.substr(29, 1);
    record->train_category     = f.substr(30, 2);
    record->train_id           = f.substr(32, 4);
    record->headcode           = f.substr(36, 4);
    record->course_indicator   = f.substr(40, 1);
    record->train_service_code = f.substr(41, 8);
    record->portion_id         = f.substr(49, 1);
    record->power_type         = f.substr(50, 3);
    record->timing_load        = f.substr(53, 4);
    record->speed              = f.substr(57, 3);
    record->operating_chars    = f.substr(60, 6);
    record->train_class        = f.substr(66, 1);
    record->sleepers           = f.substr(67, 1);
    record->reservations       = f.substr(68, 1);
    record->connection_ind     = f.substr(69, 1);
    record->catering_code      = f.substr(70, 4);
    record->service_branding   = f.substr(74, 4);
    record->spare              = f.substr(78, 1);
    record->stp_ind            = f.substr(79, 1);

    return record;
}

std::unique_ptr<BXRecord> RouteParser::parseBX(std::string f)
{
    std::unique_ptr<BXRecord> record(new BXRecord());

    record->id             = f.substr(0, 2);
    record->traction_class = f.substr(2, 4);
    record->uic_code       = f.substr(6, 5);
    record->atoc_code      = f.substr(11, 2);
    record->timetable_code = f.substr(13, 1);
    record->reserved_1     = f.substr(14, 8);
    record->reserved_2     = f.substr(22, 1);

    return record;
}

std::unique_ptr<LORecord> RouteParser::parseLO(std::string f)
{
    std::unique_ptr<LORecord> record(new LORecord());

    record->id           = f.substr(0, 2);
    record->tiploc       = f.substr(2, 7);
    record->loc_suffix   = f.substr(9, 1);
    record->sched_depart = f.substr(10, 5);
    record->pub_depart   = f.substr(15, 4);
    record->platform     = f.substr(19, 3);
    record->line         = f.substr(22, 3);
    record->eng_allow    = f.substr(25, 2);
    record->path_allow   = f.substr(27, 2);
    record->activity     = f.substr(29, 12);
    record->perf_allow   = f.substr(41, 2);

    return record;
}

std::unique_ptr<LIRecord> RouteParser::parseLI(std::string f)
{
    std::unique_ptr<LIRecord> record(new LIRecord());

    record->id          = f.substr(0, 2);
    record->tiploc      = f.substr(2, 7);
    record->loc_suffix  = f.substr(9, 1);
    record->sched_arriv = f.substr(10, 5);
    record->sched_dep   = f.substr(15, 5);
    record->sched_pass  = f.substr(20, 5);
    record->pub_arriv   = f.substr(25, 4);
    record->pub_dep     = f.substr(29, 4);
    record->platform    = f.substr(33, 3);
    record->line        = f.substr(36, 3);
    record->path        = f.substr(39, 3);
    record->activity    = f.substr(42, 12);
    record->eng_allow   = f.substr(54, 2);
    record->path_allow  = f.substr(56, 2);
    record->perf_allow  = f.substr(58, 2);

    return record;
}

std::unique_ptr<LTRecord> RouteParser::parseLT(std::string f)
{
    std::unique_ptr<LTRecord> record(new LTRecord());

    record->id          = f.substr(0, 2);
    record->tiploc      = f.substr(2, 7);
    record->loc_suffix  = f.substr(9, 1);
    record->sched_arriv = f.substr(10, 5);
    record->pub_arriv   = f.substr(15, 4);
    record->platform    = f.substr(19, 3);
    record->path        = f.substr(22, 3);
    record->activity    = f.substr(25, 12);

    return record;
}
