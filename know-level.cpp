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

//fixed level array
vector<int>zamanLevel;

//bfs implementation
void bfs(int s, int tr){
    queue<int>q;
    
    q.push(s);
    visited[s]=true;
    
    
    while(!q.empty()){
        int u=q.front();
        q.pop();
       
      
        if(level[u]==tr) { 
                    zamanLevel.push_back(u);
                    }

        
        for(int v: adjList[u]){
            if(!visited[v]) {
                q.push(v);
                visited[v]=true;
                level[v]=level[u]+1;


               
            }
            
            
           
            

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
    int l;
    cin>>l;
    bfs(0, l);
    if(l==0){
        cout<<"0"<<endl;
    }
    else{
         if(zamanLevel.empty()){
        cout<<"-1"<<endl;
        }
    
   
    else{
      sort(zamanLevel.begin(), zamanLevel.end());
      for(int zamanshop: zamanLevel){
        cout<<zamanshop<<" ";
      }
        
    }
    }
   
    
   
    return 0;
}