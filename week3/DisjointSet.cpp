#include "DisjointSet.h"
    
/*/
 * Construct and Initialise Disjoint Set.
/*/
DS::DS(int numElements){
    elementCount = numElements;
    initialiseSet();
}

/*/
 * Get parent of a node in the set.
/*/
int DS::find(int i){ 
    while (parent[i] != i) 
        i = parent[i]; 
    return i; 
} 
  
/*/
 * Union two disjoint sets.
/*/
void DS::_union(int i, int j){ 
    int a = find(i); 
    int b = find(j); 
    parent[a] = b; 
} 

/*/
 * Initialise Disjoint set of given size.
/*/
void DS::initialiseSet(){
    parent.resize(elementCount);
    for (int i = 0; i < elementCount; i++){
        parent[i] = i;
    }
}