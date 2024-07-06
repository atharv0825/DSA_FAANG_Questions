#include<bits/stdc++.h>
using namespace std;

void make_adjList( unordered_map<int,list<int>>&adjList,vector<pair<int,int>>&edges){
    for(auto i : edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}


vector<int>shortestPath(int vertices ,int source,int destination,vector<pair<int , int >>edges){
    unordered_map<int , list<int>>adjList;
    make_adjList(adjList,edges);

    unordered_map<int , int>parent;
    unordered_map<int , bool>visited;
    queue<int>q;

    q.push(source);
    visited[source] = true;
    parent[source] = -1;

    while(!q.empty()){
        int currentNode = q.front();
        q.pop();

        for(auto neighbors : adjList[currentNode]){
            if(!visited[neighbors]){
                visited[neighbors] = true;
                parent[neighbors] = currentNode;
                q.push(neighbors);
            }
        }
    }
    
    vector<int>ans;
    int currentNode = destination;
    ans.push_back(currentNode);

    while(currentNode != source){
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    cout<<"Enter no vertices : ";
    int vertices;
    cin>>vertices;
    
    
    cout<<"Enter no of edges : ";
    int edgesCount;
    cin>>edgesCount;

    vector<pair<int , int >>edges;
    for(int i =0;i<edgesCount;i++){
        int u , v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    cout<<"Enter source node and destination node : ";
    int s ,d;
    cin>>s>>d;
    vector<int>result = shortestPath(vertices,s,d,edges);
    for(auto i : result){
        cout<<i<<" "; 
    }
}   