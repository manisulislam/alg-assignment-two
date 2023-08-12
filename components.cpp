#include<bits/stdc++.h>
using namespace std;

//range 
const int N=1e3+5;

//adjacent list
vector<int>adjList[N];

//visited bool array
bool visited[N];

//connected components sizes
vector<int>componentsSizes;


//bfs implementation
int bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    int componentSize=0;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        componentSize++;

        for(int v: adjList[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
        }
    }
    return componentSize;
    


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

    
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
            for(int i=0; i<N; i++){
        visited[i]=false;
    }
        int connectedComponentSize=bfs(i);
        componentsSizes.push_back(connectedComponentSize);

       
    }
    sort(componentsSizes.begin(), componentsSizes.end());
    

    //print size
  
         for(int sz: componentsSizes){
         cout<<sz<<" ";
    } 
    cout<<endl;

    
   
    
    
    return 0;
}