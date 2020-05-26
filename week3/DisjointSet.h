#include <vector>

using namespace std;

/*/
 * Implementation of the Disjoint Set data structure used in Kruskal's algorithm.
/*/

class DS{
    public:
    
        DS(int numElements);
    
        int find(int i); 
        
        void _union(int i, int j);
        
        void initialiseSet();
        
    private:
        int elementCount;
        
        vector<int> parent; 
};
