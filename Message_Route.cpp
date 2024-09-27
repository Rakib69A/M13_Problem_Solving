#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];
bool vis[N];
vector<int> adj[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    int src = 1, des = n;
    bfs(src);
    if (!vis[des])
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else
    {
        int x = des;
        vector<int> path;
        while(x != -1){
            path.push_back(x);
            x = parent[x];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(int val : path)
            cout<<val<<" ";
    }
    return 0;
}