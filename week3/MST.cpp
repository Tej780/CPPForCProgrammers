#include <iostream>
#include <set>
#include <algorithm>

#include "DisjointSet.h"
#include "MST.h"

/*/
 * Minimum Spanning Tree on a Graph.
/*/
MST::MST(Graph g){
    graph = g;
    if (graph.getNumberOfNodes()<2){
        cout << "Too few nodes to construct Minimum Spanning Tree\n";
        throw;
    }
}

/*/
 * Clear tree and tree weight.
/*/
void MST::initialiseMST(){
    mst.clear();
    mstWeight = 0;
}

/*/
 * Get the number of edges in the tree. Useful for debugging.
/*/
int MST::size(){
    return mst.size();
}

/*/
 * Get weight of Minimum Spanning Tree. Should be same for Prim's and Kruskal's.
/*/
int MST::getMSTWeight(){
    return mstWeight;
}
      
/*/
 * Return Minimum Spanning Tree 2D array.
/*/
vector<vector<int>> MST::getMST(){
    return mst;
}

/*/
 * Display the tree.
/*/
void MST::printMST(){
    for (auto treeNode: mst){
        cout << "<" << treeNode[0] << ">-----" << treeNode[2] << "-----<" << treeNode[1] << ">\n";
    }
}

/*/
 * Carry out Prim's algorithm on the graph.
/*/
void MST::runPrims(){
    initialiseMST();
    vector<int> treeNodes;
    
    treeNodes.push_back(0);
    
    int treeWeight = 0;
    
    while (treeNodes.size()<graph.getNumberOfNodes()){
        int min = MAX;
        int node1 = -1;
        int node2 = -1;
        
        for (int node: treeNodes){
            for (int neighbor: graph.getNeighbors(node)){
                if ((find(treeNodes.begin(), treeNodes.end(), neighbor)==treeNodes.end()) && 
                    (graph.edgeWeight(node, neighbor) < min)){
                        min = graph.edgeWeight(node, neighbor);
                        node1 = node;
                        node2 = neighbor;
                    }
            }
        }
        
        if (min==MAX){
            cout << "Graph contains disconnected node. Cannot construct Minimum Spanning Tree.\n";
            throw 20;
        }
        
        treeNodes.push_back(node2);
        treeWeight += min;
        vector<int> treeNode{node1, node2, min};
        mst.push_back(treeNode);
    }
    mstWeight = treeWeight;
}
       
/*/
 * Carry out Kruskal's algorithm on the graph.
/*/
void MST::runKruskals(){
    initialiseMST();
    
    DS ds(graph.getNumberOfNodes());
    
    int treeEdges = 0;
    
    while(treeEdges<graph.getNumberOfNodes()-1){
        
        int minWeight = MAX;
        int node1 = -1;
        int node2 = -1;
        for (int i=0; i<graph.getNumberOfNodes();i++){
            for (int j=i+1 ; j<graph.getNumberOfNodes();j++){
                if(ds.find(i) != ds.find(j) && graph.edgeWeight(i,j)<minWeight){
                    minWeight = graph.edgeWeight(i,j);
                    node1 = i;
                    node2 = j;

                }
            }
        }
        ds._union(node1, node2);
        mstWeight+=minWeight;
        vector<int> treeNode{node1, node2, minWeight};
        mst.push_back(treeNode);
        treeEdges++;
    }
}
