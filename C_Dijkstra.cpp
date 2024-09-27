#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll INF = 1e18;
const int N = 1e5+5;
ll dis[N];
int parent[N];
vector<pair<int,int>> adj[N];
class cmp{
    public:
    bool operator()(pair<int,ll> a, pair<int,ll> b){
        return a.second > b.second;
    }
};
void dijkstra(int src){
    priority_queue<pair<int,ll>, vector<pair<int,ll>> , cmp> pq;
    pq.push({src,0});
    dis[src] = 0;
    while(!pq.empty()){
        pair<int,ll> par = pq.top();
        pq.pop();
        int node = par.first;
        ll cost = par.second;
        for(pair<int,int> child : adj[node]){
            int childNode = child.first;
            ll childCost = child.second;
            if(cost + childCost < dis[childNode]){
                dis[childNode] = cost + childCost;
                pq.push({childNode,dis[childNode]});
                parent[childNode] = node;
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++){
        dis[i] = INF;
    }
    memset(parent,-1,sizeof(parent));
    dijkstra(1);
    if(dis[n] == INF){
        cout<<-1<<endl;
        return 0;
    }
    int x = n;
    vector<int> path;
    while(x != -1){
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(),path.end());
    for(int val : path)
        cout<<val<<" ";
    cout<<endl;
    return 0;
}