#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int parent[N];
int sz[N];
void dsu_init(int n){
    for(int i=1;i<=n;i++){
        parent[i] = -1;
        sz[i] = 1;
    }
}
int dsu_find(int node){
    if(parent[node] == -1)
        return node;
    int leader = dsu_find(parent[node]);
    parent[node] = leader;
    return leader;
}
void dsu_union_by_size(int node1,int node2){
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);

    if(sz[leaderA] > sz[leaderB]){
        parent[leaderB] = leaderA;
        sz[leaderA] += sz[leaderB];
    }
    else if(sz[leaderA] < sz[leaderB]){
        parent[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
    else{
        parent[leaderA] = leaderB;
        sz[leaderB] += sz[leaderA];
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    dsu_init(n);
    vector<pair<int,int>> v;
    while(e--){
        int a,b;
        cin>>a>>b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB) continue;
        else{
            dsu_union_by_size(a,b);
        }
    }
    int cnt  = 0;
    for(int i=1;i<n;i++){
        int leaderA = dsu_find(i);
        int leaderB = dsu_find(i+1);
        if(leaderA == leaderB) continue;
        else{
            dsu_union_by_size(i,i+1);
            cnt++;
            v.push_back({i,i+1});
        }
    }
    cout<<cnt<<endl;
    for(auto val : v)
        cout<<val.first<<" "<<val.second<<" ";
    cout<<endl;
    return 0;
}