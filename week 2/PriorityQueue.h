#include <map>
#include <limits>

using namespace std;

/*/
 * Implementation of Priority Queue data structure.
 * In the context of the shortest path algorithm, priority is the minimum
 * distance between the source node and another given node.
 * The lowest priority <=> shortest distance.
/*/

class PQ{
    public:
        void chgPriority(int node, int dist);
        
        void removeNode(int node);
        
        int minPriority();
        
        bool contains(int node);
        
        void insert(int node, int dist);
        
        int getPriority(int node);
        
        int size();
        
        void printPQ();
        
    private:
        map<int, int> queue;
};
