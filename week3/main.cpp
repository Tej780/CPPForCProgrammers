#include <iostream>

#include "MST.h"

using namespace std;

/*/
 * Run Prim's and Kruskal's algorithm on a randomly generated graph.
/*/


int main(){
    int nodeNum = 10;
    float density = 0.5;
    int weightRange = 5;
    
    Graph g(nodeNum);
    g.seedRandomNumberGenerators();
    
    cout << "Graph with " << nodeNum << " nodes, edge density " << density << " and edge distance range " << weightRange << "\n";
    
    g.randomEdges(density, weightRange);
    
    

    MST mst(g);

    mst.runPrims();
    mst.printMST();
    cout << mst.getMSTWeight() << "\n";
    
    cout << "\n-------------------------\n\n";
    
    mst.runKruskals();
    mst.printMST();
    cout << mst.getMSTWeight() << "\n";

    return 0;
}