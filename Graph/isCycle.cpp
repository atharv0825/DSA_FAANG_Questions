#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

bool isCycle(int i , unordered_map<int, bool>&visited ,unordered_map<int ,list<int>>&adjList){
    queue<int>q;
    unordered_map<int,int>parent;

    parent[i] = -1;
    visited[i] = true;

    q.push(i);

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto neighbour : adjList[frontNode]){
            if(visited[neighbour]&& parent[frontNode] != neighbour)
                return true;
            else if(!visited[neighbour]){
                q.push(neighbour);
                parent[neighbour] = frontNode;
                visited[neighbour] = true;
            }    
        }
    }

    return false;
}

string cycleDetection(int e , int n , vector<pair<int,int>>&edges){
    unordered_map<int ,list<int>>adjList;
    for(auto i : edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    unordered_map<int, bool>visited;
    for(int i =0;i<n;i++){
        if(!visited[i]){
            bool result = isCycle(i,visited,adjList);
            if(result)
                return "Yes";
        }
    }

    return "NO";
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

    cout<<cycleDetection(edgesCount , vertices , edges);

    return 0;
}   