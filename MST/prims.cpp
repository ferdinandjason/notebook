#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

void Prims(){
    int V;vector<ii> adj[V];bool visited[V];
    memset(visited,false,sizeof visited);
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    int start=0; pq.push({0,start});
    while(!pq.empty()){
       int u=pq.top().second;pq.pop();
       visited[u]=true;
       for(auto x:adj[u]){
           if(!visited[x.second]){
            pq.push(make_pair(x.first,x.second));
           } 
        }
    }
}
