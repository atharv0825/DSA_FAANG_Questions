#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>&disc,vector<int>&lowTime,int parent,unordered_map<int,bool>&visited,vector<vector<int>>&result, int node,unordered_map<int,list<int>>&adjList,int timer ){
    visited[node] = true;
    lowTime[node] = disc[node] = timer++;

    for(auto neighbour : adjList[node]){
        if(neighbour == parent)
            continue;
        if(!visited[neighbour]){
            dfs(disc,lowTime,node,visited,result,neighbour,adjList,timer);
            lowTime[node] = min(lowTime[node] , lowTime[neighbour]);
            if(lowTime[neighbour]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }else{
            lowTime[node] = min(lowTime[node],disc[neighbour]);
        }
    }

}

vector<vector<int>>findBridges(vector<vector<int>>&edges, int vertices , int edgesCount){
    unordered_map<int,list<int>>adjList;
    for(int i = 0;i<edgesCount;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int timer = 0;
    vector<int>disc(vertices);
    vector<int>lowTime(vertices);
    int parent = -1;
    unordered_map<int,bool>visited;
    vector<vector<int>>result;

    for(int i =0;i<vertices;i++){
        if(!visited[i])
            dfs(disc,lowTime,parent,visited,result,i,adjList,timer);
    }

    return result;
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

    vector<vector<int>> bridges = findBridges(edges, v, e);

    cout << "Bridges in the graph are:" << endl;
    for (auto bridge : bridges) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}