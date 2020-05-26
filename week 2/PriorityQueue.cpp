#include <iostream>
#include <tuple>

#include "PriorityQueue.h"

/*/
 * Update priority of given node.
/*/
void PQ::chgPriority(int node, int dist){
    queue[node] = dist;
}

/*/
 * Remove node from queue.
/*/
void PQ::removeNode(int node){
    queue.erase(node);
}

/*/
 * Find node with lowest priority (distance from source).
/*/
int PQ::minPriority(){
    if (queue.size()<=0){
        cout << "Queue is empty";
        throw 20;
    }
    
    int node = -1;
    int minDist = numeric_limits<int>::max();
    for (auto element=queue.begin(); element!=queue.end(); element++){
        if (element->second < minDist) {
            minDist = element->second;
            node = element->first;
        }
    }
    return node;
}

/*/
 * Check if node is in the queue.
/*/
bool PQ::contains(int node){
    return (queue.find(node)!=queue.end());
}

/*/
 * Add node to queue with given priority (distance).
/*/
void PQ::insert(int node, int dist){
    queue.insert(make_pair(node, dist));
} 

/*/
 * Get priority of given node.
/*/
int PQ::getPriority(int node){
    return queue[node];
}

/*/
 * Get number of nodes in queue.
/*/
int PQ::size(){
    return queue.size();
}

/*/
 * Display the nodes in the queue and their corresponding priorities.
 * Useful for debugging purposes.
/*/
void PQ::printPQ(){
    for (auto element=queue.begin(); element!=queue.end(); element++){
        cout << "(" <<  element->first << ", " << element->second << ")\n";
    }
    
    cout << "\n";
}