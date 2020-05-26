#include <vector>
#include <random>
#include <limits>

using namespace std;

const int MAX = numeric_limits<int>::max();

/*/
 * Connection Matrix representation of undirected graph with n nodes and no loops.
 * Edges are generated pseudo-randomly and have variable positive lengths.
/*/

class Graph{
    public:
        Graph(const int numberOfNodes = 0);
        
        Graph(string filePath);
        
        Graph(const int numberOfNodes, float density);
        
        void initialiseAdjMat();
        
        void addEdge(int node1, int node2, int weight);
        
        void deleteEdge(int node1, int node2);
        
        bool edgeExists(int node1, int node2);
        
        int edgeWeight(int node1, int node2);
        
        bool nodeExists(int node);
        
        void randomEdges(float density, int weightRange = 10);
        
        vector<vector<int>> getGraph();
        
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