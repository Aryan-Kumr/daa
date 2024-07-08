#include <iostream>
#include <queue>
using namespace std;

void bfs(vector<int>adj[], int StartingNode, int v) {
    vector<int> vis(v,0);
    vector<int> ans;
    queue<int> q;
    q.push(StartingNode);
    vis[StartingNode] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); ++i) {
            int neighbor = adj[node][i];
            if (!vis[neighbor]) {
                vis[neighbor] = 1;  // Mark neighbor as visited
                q.push(neighbor);
            }
        } 
    }
    cout<<"bfs traversal"<<endl;
    for(int i = 0; i < ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    vector<int>adj[5];
    adj[0].push_back(1);  // Node 0 is connected to node 1
    adj[0].push_back(2);  // Node 0 is also connected to node 2
    adj[1].push_back(3);  // Node 1 is connected to node 3
    adj[2].push_back(4);  // Node 2 is connected to node 4
 
    
    for (int i = 0; i < 5; ++i) {
        cout << "Adjacency list of node " << i << ": ";
        for (int j = 0; j < adj[i].size(); ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    
    bfs(adj, 0, 5);


    return 0;
}