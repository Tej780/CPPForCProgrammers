#include <vector>
#include <random>

using namespace std;

/*/
 * Connection Matrix representation of undirected graph with n nodes and no loops.
 * Edges are generated pseudo-randomly and have variable positive lengths.
 * Connection matrix was chosen mainly for familiarity, but also to simplify some iterative processes.
/*/

class Graph{
    public:
        Graph(const int numberOfNodes = 0);
        
        Graph(const int numberOfNodes, float density);
        
        void initialiseAdjMat();
        
        void addEdge(int node1, int node2, int dist);
        
        void deleteEdge(int node1, int node2);
        
        bool edgeExists(int node1, int node2);
        
        int edgeDist(int node1, int node2);
        
        bool nodeExists(int node);
        
        void randomEdges(float density, int distRange = 1);
        
        void printGraph();
        
        void seedRandomNumberGenerators();
        
        vector<int> getNeighbors(int node);
        
        int getNumberOfNodes();
        
        int getNumberOfEdges();

    private:
        int nodeCount;
        
        int edgeCount;
        
        vector<vector<int>> adjMat;
        
        default_random_engine gen;

        uniform_real_distribution<> dist;
};