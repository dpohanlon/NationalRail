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

#include "Utils/MapUtils.hpp"

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


void addAdj(map<string, set<string> > & adj, vector<string> & stations)
{
    for(int i = 0; i < stations.size(); i++){
        for(int j = 0; j < stations.size(); j++){
            if(stations[i] != stations[j]){
                mapUtils::insertWith(adj, stations[i], stations[j],
                    [](set<string> & vs, string & s){ vs.insert(s); }
                );
            }
        }
    }
}

Vertex addVertex(Graph & g, map<string, Vertex> & vs, string key)
{
    Vertex v;

    // if in map
    if(vs.find(key) != vs.end()){
        // use map vertex
        v = vs[key];
    }
    else{
        // else make a new vertex + add to map, graph
        v = boost::add_vertex(g);
        vs.insert(make_pair(key, v));
        g[v].name = key;
    }
    
    return v;
}

int main(int argc, char const *argv[])
{
    RouteParser routeParser("ttf078/TTISF078.MCA");

    vector<unique_ptr<RouteRecord> > routes(move(routeParser.routes));

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
            Vertex v1 = addVertex(g, vs, o.first);
            Vertex v2 = addVertex(g, vs, i);

            boost::add_edge(v1, v2, g);
        }
    }

    std::ofstream f("rail.dot");
    boost::write_graphviz(f, g, boost::make_label_writer(boost::get(&Data::name, g)));
    f.close();

    return 0;
}
