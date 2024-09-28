#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> adj[N];
bool vis[N];
void bfs(int src, int dis[])
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    dis[src] = 0;
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
                dis[child] = dis[par] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)
    {
        int n, r;
        cin >> n >> r;
        while (r--)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int dis1[N];
        int dis2[N];
        memset(vis, false, sizeof(vis));
        memset(dis1, -1, sizeof(dis1));
        int s, d;
        cin >> s >> d;

        bfs(s,dis1);
        
        memset(vis,false,sizeof(vis));
        memset(dis2, -1, sizeof(dis2));
        bfs(d,dis2);
       
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            mx = max(mx,dis1[i]+dis2[i]);
        }
        cout<<"Case "<<i<<": "<<mx<<endl;
        for(int i=0;i<n;i++){
            adj[i].clear();
        }
    }
    return 0;
}