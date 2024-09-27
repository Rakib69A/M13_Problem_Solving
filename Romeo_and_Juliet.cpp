#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int parent[N];
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
                vis[child] = true;
                q.push(child);
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
    int src, des, steps;
    cin >> src >> des >> steps;
    bfs(src);
    if (!vis[des])
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        int x = des;
        vector<int> path;
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
        }
        // for(int val : path)
        //     cout<<val<<" ";
        // cout<<endl;
        float m = (path.size()-1) / 2.0;
        // cout<<ceil(m)<<endl;
        if(ceil(m) <= steps)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}