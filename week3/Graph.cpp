#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Graph.h"

/*/
 * Construct disconnected graph with N nodes.
/*/
Graph::Graph(const int numberOfNodes){
    nodeCount = numberOfNodes;
    edgeCount = 0;
    initialiseAdjMat();
}

/*/
 * Construct graph with random edges based on given density.
/*/
Graph::Graph(const int numberOfNodes, float density){
    nodeCount = numberOfNodes;
    initialiseAdjMat();
    randomEdges(density);
}

/*/
 * Construct graph from data file.
 * Each line should represent an edge in the format (Start node, End node, Weight).
 * First line of the file is the number of nodes.
/*/
Graph::Graph(string filePath){
    ifstream fin; 
    fin.open((filePath));
    string line;
    
    if (fin.is_open()){
        
        getline ( fin, line );
        stringstream data(line);
        data >> nodeCount;
        
        edgeCount = 0;
        initialiseAdjMat();
        
        vector<vector<int>> edgeList;

        while ( getline ( fin, line )){

            stringstream data(line);
            
            int start, stop, weight;
            
            data >> start >> stop >> weight;
            
            vector<int> edge{start,stop,weight};
            edgeList.push_back(edge);
            edgeCount++;
		}

        for(auto edge:edgeList){
            adjMat[edge[0]][edge[1]]=edge[2];
        }
    }
}

/*/
 * Create empty NxN Connection Matrix representing the graph.
/*/
void Graph::initialiseAdjMat(){
    adjMat.resize(nodeCount);
        for (int i=0; i<nodeCount; i++){
            adjMat[i] = vector<int> (nodeCount,MAX);
        }
}

/*/
 * Add edge of given weight connecting node1 -> node2 
 * (and therefore node2 -> node1) to Connection Matrix.
/*/
void Graph::addEdge(int node1, int node2, int dist){
    edgeCount++;
    // Added edges are undirected
    adjMat[node1][node2] = dist;
    adjMat[node2][node1] = dist;
}

/*/
 * Remove edge between node1 and node 2 from Connection Matrix.
/*/
void Graph::deleteEdge(int node1, int node2){
    edgeCount--;
    adjMat[node1][node2] = 0;
    adjMat[node2][node1] = 0;
}

/*/
 * Check if edge connecting node1 and node 2 exist.
 * Assumes node1 -> node2 exists <=> node2 -> node1 exists.
/*/
bool Graph::edgeExists(int node1, int node2){
    return (adjMat[node1][node2] > 0);
}

/*/
 * Check if node N exists in graph.
/*/
bool Graph::nodeExists(int node){
    return (node>=0 && node<=nodeCount);
}

/*/
 * Find edge length between two directly connected nodes.
/*/
int Graph::edgeWeight(int node1, int node2){
    return adjMat[node1][node2];
}

/*/
 * (Re)initialise graph and add edges randomly with given density 
 * and random edge lengths between 1 -> distRange.
/*/
void Graph::randomEdges(float density, int distRange){
    
    initialiseAdjMat();
    edgeCount = 0;
    int edgeCounter = 0;
    for (int i=0; i<nodeCount; i++){
        
        // Starting j from i+1 avoids double counting of edges
        // i.e. we are looking at the upper triangle of the connection matrix.
        for (int j=i+1; j<nodeCount; j++){ 
            if ((dist(gen)<density)) {
                edgeCount++;
                int weight = rand() % distRange + 1;
                adjMat[i][j] = weight;
                adjMat[j][i] = weight;
            }
        }
    }
}

/*/
 * Get the Connection Matrix.
/*/
vector<vector<int>> Graph::getGraph(){
    return adjMat;
}

/*/
 * Display the Connection Matrix.
/*/
void Graph::printGraph(){
    for (int i=0; i<nodeCount; ++i){
        for (int j=0; j<nodeCount; ++j){
            cout << adjMat[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

/*/
 * Seed pseudo-random number generators with system clock.
/*/
void Graph::seedRandomNumberGenerators(){
    srand(time(NULL));
    gen.seed(time(NULL));
}

/*/
 * Find all directly connected nodes.
/*/
vector<int> Graph::getNeighbors(int node){
    vector<int> neighbors;
    for (int i=0; i<nodeCount; i++){
        if (adjMat[node][i] > 0){
            neighbors.push_back(i);
        }
    }
    return neighbors;
}

/*/
 * Node number getter.
/*/
int Graph::getNumberOfNodes(){
    return nodeCount;
}

/*/
 * Edge number getter.
/*/
int Graph::getNumberOfEdges(){
    return edgeCount;
}



