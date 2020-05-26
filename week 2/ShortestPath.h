#include <map>

#include "Graph.h"

/*/
 * Implementation of Dijsktra's shortest path algorithm on a given graph.
/*/

class SP{
    public:
        SP(Graph g, int start);
        
        void findShortestPath(int end_node);
        
        float averagePathLength();
        
        void printShortestDist();
        
        void printShortestPath();
        
        int getShortestDist();
        
        map<int,int> getShortestPath();
        
    private:
        Graph graph;
        
        int start_node;
        
        int shortestDist;
        
        map<int,int> shortestPath;
};
