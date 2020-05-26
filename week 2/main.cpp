#include <iostream>

#include "ShortestPath.h"

using namespace std;

/*/
 * Run Dijsktra "loopNum" times to get average across multiple graph configurations
 * for given set parameters.
/*/
void monteCarlo(int loopNum = 1,
    int nodeNum = 50,
    float density = 0.7,
    int distanceRange = 100){

    Graph g(nodeNum);
    g.seedRandomNumberGenerators();
    
    cout << "Graph with " << nodeNum << " nodes, edge density " << density << " and edge distance range " << distanceRange << "\n";
    
    float acc = 0;
    
    for (int i=0;i<loopNum;i++){
        g.randomEdges(density, distanceRange);
        SP sp (g, 0);
        float apl =  sp.averagePathLength();
        //cout << "Average Path length: " << apl << "\n";
        acc += apl;
    }
    cout << "Monte Carlo Path length after "<< loopNum <<" loop(s): " << (acc/loopNum) << "\n";
}

int main(){
    monteCarlo(100,50,0.2,10);
    monteCarlo(100,50,0.4,10);
    
    return 0;
}