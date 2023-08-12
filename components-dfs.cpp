#include<bits/stdc++.h>
using namespace std;

//range 
const int N=1e3+5;

//adjacent list
vector<int>adjList[N];

//visited bool array
bool visited[N];

//connected component size
vector<int>connectedComponentSize[N];


//connected components sizes
vector<int>componentsSizes;

//track connected components
int cc=0;

//dfs implementation
void dfs(int u){
    visited[u]=true;
    connectedComponentSize[cc+1].push_back(u);
    for(int v: adjList[u]){
        if(visited[v]==true) continue;
        dfs(v);
    }



}

 


int main(){
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);

    }
    dfs(0);

    for(int i=0; i<N; i++){
        if(visited[i]) continue;
       
        cc++;
        dfs(i);
    }
    for(int i=1; i<=cc; i++){
        componentsSizes.push_back(connectedComponentSize[i].size());
    }
    
    
    sort(componentsSizes.begin(), componentsSizes.end());
    

    //print size
   for(int size: componentsSizes){
    if(size>1){
        cout<<size<<" ";
    }
   }

    
   
    
    
    return 0;
}