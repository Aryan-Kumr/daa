#include <iostream>
#include <queue>
#include <vector> 
using namespace std;
vector<int> ans;
void BFS(vector<int> adj[], int startNode, int v) {
    vector<int> vis(v, 0);
    queue<int> q;
    q.push(startNode);
    vis[startNode] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] = 1;  
            }
        }
    }
}
int main()
{
    vector<int> adj[5];   // v = 5
    adj[0].push_back(1);                    //            0 
    adj[0].push_back(2);                   //           | | |
    adj[0].push_back(3);                  //            1  2 3 
    adj[1].push_back(0);                //                 |
    adj[2].push_back(0);             //                    4
    adj[2].push_back(4);
    adj[3].push_back(0);
    adj[4].push_back(2);
    BFS(adj, 0, 5);
    for(auto it: ans) {
        cout<<it<<" ";
    }
    return 0;
}
