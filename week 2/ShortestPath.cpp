#include <iostream>

#include "ShortestPath.h"
#include "PriorityQueue.h"

/*/
 * Set up graph and starting node for shortest path algorithm
/*/
SP::SP(Graph g, int start){
    graph = g;
    if (!graph.nodeExists(start)){
        cout << "Start node " << start << " is not in the Graph\n";
        throw 20;
    }
    start_node = start;
}

/*/
 * Run Dijkstra's algorithm on graph from starting node
/*/
void SP::findShortestPath(int end_node){
    if (!graph.nodeExists(end_node)){
        cout << "Node " << end_node << " is not in the Graph\n";
        throw 20;
    }
    
    PQ openSet;

    map<int,int> closedSet;
    
    for (int i=-1; i<graph.getNumberOfNodes(); i++){
        openSet.insert(i, numeric_limits<int>::max());
    }
    
    openSet.chgPriority(start_node,0);
    
    while (closedSet.size() < graph.getNumberOfNodes()) {
        int closestNode = openSet.minPriority();
        int distanceToClosestNode = openSet.getPriority(closestNode);
        if (distanceToClosestNode==numeric_limits<int>::max()){
            cout << "No path between " << start_node << " and " << end_node << "\n";
            throw 20;
        }
        
        openSet.removeNode(closestNode);
        closedSet.insert(make_pair(distanceToClosestNode, closestNode));
        
        if (closestNode==end_node){
            shortestDist = closedSet.rbegin()->first ;
            shortestPath = closedSet;
            return;
        }

        vector<int> neighbors = graph.getNeighbors(closestNode);
        for (auto neighbor: neighbors){
            int totalDist = distanceToClosestNode + graph.edgeDist(closestNode, neighbor);
            if (openSet.contains(neighbor) && totalDist < openSet.getPriority(neighbor)){
                openSet.chgPriority(neighbor, totalDist);
            }
        }
        
    }
}

/*/
 * Run Dijkstra's algorithm from starting node to each and every other node in the graph,
 * then find the average across all shortest paths.
/*/
float SP::averagePathLength(){
    float acc = 0.0;
    int counter = 0;
    for (int i = 1; i < graph.getNumberOfNodes(); i++){
        try{
            findShortestPath(i);
            int sd = getShortestDist();
            acc += sd;
            //cout << "Node "<< i << ": Path length: " << sd << "\n";
            counter++;
        }catch(int e){
            continue;
        }
    }
    return (acc/counter);
}

/*/
 * After running Dijkstra's algorithm on the graph, display the shortest path
 * including distances to all intermediate nodes.
/*/
void SP::printShortestPath(){
    for (auto it = shortestPath.begin(); it!=shortestPath.end();it++){
        cout << "Node: " << it->second << " Distance:" << it->first << "\n" ;
    }
    cout << endl;
}

/*/
 * After running Dijkstra's algorithm on the graph, 
 * get shortest distance to end node.
/*/
int SP::getShortestDist(){
    return shortestDist;
}

/*/
 * After running Dijkstra's algorithm on the graph, 
 * get shortest path to end node.
/*/
map<int,int> SP::getShortestPath(){
    return shortestPath;
}
        