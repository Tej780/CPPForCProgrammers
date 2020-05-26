#include <vector>
#include <random>

#include "Graph.h"

using namespace std;

/*/
 * Minimum Spanning Tree implementation with Kruskal's and Prim's algorithms built in.
 * Each element holds the start node, end node and weight of an edge in the tree.
/*/

class MST{
    public:
    
        MST(Graph g);
        
        void runPrims();
        
        void runKruskals();
        
        int getMSTWeight();
        
        vector<vector<int>> getMST();
        
        void printMST();
        
        void initialiseMST();
        
        int size();
        
    private:
        Graph graph;
        
        vector<vector<int>> mst;
        
        int mstWeight;
    
};