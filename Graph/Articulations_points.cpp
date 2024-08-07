//find the articulation points in the graph
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,int parent,vector<int>&disc,vector<int>&low,unordered_map<int,bool>&visited,vector<int>&ap,unordered_map<int,list<int>>&adjList,int &timer){
    visited[node] = true;
    disc[node] = low[node] = timer++;
    int child =0;

    for(auto neighbour : adjList[node]){
        if(neighbour == parent)
            continue;

        if(!visited[neighbour]){
            dfs(neighbour,node,disc,low,visited,ap,adjList,timer);
            low[node] = min(low[node],low[neighbour]);
            //condition for Articulation points 
            if(low[neighbour] >= disc[node] && parent != -1){
                ap[node] = 1;
            }
            child++;
        }else{
            low[node] = min(low[node],disc[neighbour]);
        }
    }

    if(parent == -1 && child>1){
        ap[node] = 1;
    }
}

vector<int>Articulation_point(vector<vector<int>>&edges ,int v , int e){
    unordered_map<int,list<int>>adjList;
    for(int i =0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int>lowTime(v,-1);
    vector<int>disc(v,-1);
    unordered_map<int,bool>visited;
    int parent = -1;
    vector<int>ap(v,0);

    for(int i =0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,disc,lowTime,visited,ap,adjList,timer);
        }
    }

    return ap;
}

int main(){
    int v = 5; // Number of vertices
    int e = 5; // Number of edges
    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {0, 3},
        {3, 4}
    };

    vector<int> bridges = Articulation_point(edges, v, e);

    cout << "Bridges in the graph are:" << endl;
    for (auto bridge : bridges) {
        cout << bridge << endl;
    }

    return 0;
}