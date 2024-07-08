#include <iostream>
using namespace std;
void floyd(int graph[4][4], int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                graph[i][j] = min(graph[i][j], (graph[i][k] + graph[k][j]));
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int graph[4][4] = {{ 0, 5, 999, 10 },
                        { 999, 0, 3, 999},
                        { 999, 999, 0, 1 },
                        { 999, 999, 999, 0 }};
    cout<<"transitive closure is: "<<endl;
    floyd(graph, 4);

    return 0;
}