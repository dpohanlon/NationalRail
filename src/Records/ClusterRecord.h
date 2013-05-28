#ifndef CLUSTERRECORD_H
#define CLUSTERRECORD_H

#include <string>

class ClusterRecord
{
public:
    ClusterRecord(void);
    
    std::string update_marker;
    std::string cluster_id;
    std::string cluster_nlc;
    std::string end_date;
    std::string start_date;
};

#endif
