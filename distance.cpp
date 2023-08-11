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

//bfs implementation
void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v: adjList[u]){
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v]=level[u]+1;

        }
    }
}

int main(){
    int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a , b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);

    }
    

    //query input
    int  q;
    cin>>q;
    while(q--){
        int s, d;
        cin>>s>>d;
        bfs(s);
        //check s and d visited kina
        if(visited[s]==true && visited[d]==true){
            cout<<level[d]<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
         for(int i=0; i<N; i++){
            //reset
            level[i]=0;
            visited[i]=0;
           
        }
        
       
        
       
        

    }

    
    return 0;
}