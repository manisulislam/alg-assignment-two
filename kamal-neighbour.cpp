#include<bits/stdc++.h>
using namespace std;
//range
const int N=1e5+7;

//adjacency list
vector<int>adjList[N];

int main(){
     int n, e;
    cin>>n>>e;
    for(int i=0; i<e; i++){
        int a , b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);

    }
    int k;
    cin>>k;
    cout<<adjList[k].size()<<endl;

   


    
    
    return 0;
}