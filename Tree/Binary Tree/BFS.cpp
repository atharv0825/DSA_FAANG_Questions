#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include <queue>

using namespace std;

void make_adjList(vector<pair<int , int>>edges,unordered_map<int ,list<int>>&adjList){
    for(auto i : edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void bfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, vector<int>& ans, int node){
    queue<int>q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);

        for(auto neighbour : adjList.at(frontNode)){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

vector<int>BFS(int start , int vertices ,vector<pair<int , int>>edges){
    vector<int>ans;
    unordered_map<int,bool>visited;
    unordered_map<int ,list<int>>adjList;

    make_adjList(edges,adjList);

    if(!visited[start]){
        bfs(adjList,visited,ans,start);
    }

    for(auto pair : adjList){
        int node = pair.first;
        if(!visited[node]){
            bfs(adjList,visited,ans,node);
        }
    }

    return ans;
}

int main(){
    cout<<"Enter Vertices : ";
    int vertices;
    cin>>vertices;

    cout<<"Enter Edges : ";
    int edgesCount;
    cin>>edgesCount;

    vector<pair<int, int>> edges;
    for(int i =0;i<edgesCount;i++){
        int u , v ;
        cin>>u>>v;
        edges.push_back({u,v});
    }


    int start;
    cout<<"starting Node : ";
    cin>>start;

    vector<int>result = BFS(start,vertices,edges);

    for(auto i : result){
        cout<<" "<<i;
    }

    return 0;
}