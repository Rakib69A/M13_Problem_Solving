#include <bits/stdc++.h>
using namespace std;
int row,col;
char graph[25][25];
bool vis[25][25];
bool valid(int i, int j){
    return (i>=0 && i<row && j>=0 && j<col);
}
vector<pair<int,int>> d = {{0,1},{0,-1},{-1,0},{1,0}};
int cnt;
void dfs(int si, int sj){
    vis[si][sj] = true;
    cnt++;
    for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int cj =  sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && graph[ci][cj] != '#'){
            dfs(ci,cj);
        }
    }
}

int main() {
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>col>>row;
        int si,sj;
        cnt = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>graph[i][j];
                if(graph[i][j] == '@'){
                    si = i;
                    sj = j;
                }
            }
        }
        memset(vis,false,sizeof(vis));
        dfs(si,sj);
        cout<<"Case "<<i<<": "<<cnt<<endl;
    }
    return 0;
}
