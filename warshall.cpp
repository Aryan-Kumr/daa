#include <iostream>
using namespace std;
void warshall(int graphs[4][4], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graphs[i][j] = graphs[i][j] || (graphs[i][k] && graphs[k][j]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int k = 0; k < n; k++) {
            cout<<graphs[i][k]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int graphs[4][4] = {{0, 1, 0, 0},
                   {0, 0, 1, 0},
                   {0, 0, 0, 1},
                   {1, 0, 0, 0}};
    cout<<"transitive closure is: "<<endl;
    warshall(graphs, 4);

    return 0;
}