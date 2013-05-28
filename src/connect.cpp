#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/undirected_graph.hpp>
#include <boost/graph/labeled_graph.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/graphviz.hpp>

#include "Parsers/RouteParser.h"
#include "Records/RouteRecord.h"

#include "Parsers/MSNParser.h"
#include "Records/MasterStationRecord.h"

using namespace std;

class Data
{
public:
    string name;
}; 

typedef boost::adjacency_list< boost::vecS,
                               boost::vecS,
                               boost::undirectedS,
                               Data > Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

void add(map<string, set<string> > & adj, string key, string value)
{
    map<string, set<string> >::iterator l = adj.find(key);
    if(l != adj.end()){
        (l->second).insert(value);
    }
    else{
        set<string> tmp = { value };
        adj.insert(make_pair(key, tmp));
    }
}

void addAdj(map<string, set<string> > & adj, vector<string> stations)
{
    for(int i = 0; i < stations.size(); i++){
        for(int j = 0; j < stations.size(); j++){
            if(stations[i] != stations[j]) add(adj, stations[i], stations[j]);
        }
    }
}

int main(int argc, char const *argv[])
{
    RouteParser routeParser("ttf078/TTISF078.MCA");
    // MSNParser   stationParser("test.MSN");

    vector<unique_ptr<RouteRecord> > routes(move(routeParser.routes));
    // vector<unique_ptr<StationRecord> > stations(move(stationParser.stations));

    map<string, set<string> > adj;

    vector<unique_ptr<RouteRecord> >::iterator r;

    for(r = routes.begin(); r != routes.end(); r++){
        if(
           (*r)->bs->days_run != "0000011" &&
           (*r)->bs->days_run != "0000001" &&
           (*r)->bs->days_run != "0000010" &&
           (*r)->bs->train_status == "P" &&
           (*r)->bs->stp_ind == "P" &&
           ((*r)->bs->train_category == "OO" ||
           (*r)->bs->train_category == "XX")
           ){ // No weirdness

            vector<string> tStations;

            tStations.push_back((*r)->lo->tiploc);

            vector<unique_ptr<LIRecord> >::iterator i;
            for(i = (*r)->li.begin(); i != (*r)->li.end(); i++){
                tStations.push_back((*i)->tiploc);
            }

            tStations.push_back((*r)->lt->tiploc);

            addAdj(adj, tStations);
        }
    }

    Graph g;

    map<string, Vertex> vs;

    for(pair<string, set<string> > o : adj){
        for(string i : o.second){
            Vertex v1;
            Vertex v2;

            // if in map
            if(vs.find(o.first) != vs.end()){
                // use map vertex
                v1 = vs[o.first];
            }
            else{
                // else make a new vertex + add to map, graph
                v1 = boost::add_vertex(g);
                vs.insert(make_pair(o.first, v1));
                g[v1].name = o.first;
            }

            // if in map
            if(vs.find(i) != vs.end()){
                // use map vertex
                v2 = vs[i];
            }
            else{
                // else make a new vertex + add to map, graph
                v2 = boost::add_vertex(g);
                vs.insert(make_pair(i, v2));
                g[v2].name = i;
            }

            boost::add_edge(v1, v2, g);
        }
    }

    std::ofstream f("rail.dot");
    boost::write_graphviz(f, g, boost::make_label_writer(boost::get(&Data::name, g)));
    f.close();

    return 0;
}
