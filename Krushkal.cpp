#include <iostream>
#include <vector>
using namespace std;
# define I 999
int edges[3][9] = {{1,1,2,2,3,4,4,5,5},
                   {2,6,3,7,4,5,7,6,7},
                   {25,5,12,10,8,16,14,20,18}};
vector<int> set(8, -1);   //7 vertices
vector<int> included(9, 0);  //edges are included or not
int t[2][6];   //stores result

void myUnion(int u, int v) {
    if(set[u] < set[v]) {
        set[u] = set[u] + set[v];
        set[v] = u;
    } else {
        set[v] = set[v] + set[u];
        set[u] = v;
    }
}
int find(int u) {   //find extreme parent
    int x = u;
    //int v = 0;
    while(set[x] > 0) {
        x = set[x];
    }
    // while(u != x) {
    //     v = set[u];
    //     set[u] = x;
    //     u = v;
    // }
    return x;
}
int main() {
   int i = 0, min, n = 7, e = 9, u, v, k;
   while(i < n-1) {
       min = I;
       for(int j = 0; j < e; j++) {
           if(included[j] == 0 && edges[2][j] < min) {
               min = edges[2][j];
               u = edges[0][j];
               v = edges[1][j];
               k = j;
           }
       }
       if(find(u) != find(v)) {   //no cycle found
           t[0][i] = u;
           t[1][i] = v;
           myUnion(find(u), find(v));
           i++;
       }
       included[k] = 1;
   }
   for(int i = 0; i < n-1; i++) {
       cout<<"("<<t[0][i]<<"--->"<<t[1][i]<<")"<<endl;
   }
    return 0;
}