#include<bits/stdc++.h>
using namespace std;
//range
const int N=1e5+7;

//adjacency list
vector<int>adjList[N];

//visited bool array
bool visited[N];

//level array
int level[N];


//dfs implementation
int cnt=0;
void dfs(int u){
    visited[u]=true;
    cnt++;
    for(int v: adjList[u]){
        if(visited[v]==true) continue;
        dfs(v);
        
    }
   
}
int main(){
     int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a , b;
        cin>>a>>b;
        adjList[a].push_back(b);
        

    }
    int k;
    cin>>k;
    dfs(k);
    cout<<cnt-1<<" ";

    
    
    return 0;
}