// Convert this program to C++

// change to C++ io

// change to one line comments

// change defines of constants to const

// change array to vector<>

// inline any short function



#include <iostream>
#include <vector>

using namespace std;

const int N=40;

inline void sum(int*p, int n, vector<int> d){

    int i;

    *p = 0;

    for(i = 0; i < n; ++i)

        *p = *p + d[i];

    }

int main(){
    
    int i;
    
    int accum = 0;
    
    vector<int> d(N);

    
    for(i = 0; i < N; ++i)
    
        d[i] = i;
    
        sum(&accum, N, d);
    
        printf("sum is %d\n", accum);
    
        return 0;
    }