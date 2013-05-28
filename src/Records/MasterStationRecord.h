#ifndef MASTERSTATIONRECORD_H
#define MASTERSTATIONRECORD_H

#include <string>

class MasterStationRecord
{
public:
    MasterStationRecord(void);

    std::string type;
    std::string name;
    std::string tiploc;
    std::string subAlpha;
    std::string alpha;
    int         cate;
    int         easting;
    int         northing;
    bool        estimated;
    int         changeTime;
    int         footnote;
    int         region; 
};

#endif
