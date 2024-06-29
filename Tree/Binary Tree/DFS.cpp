#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<list>
using namespace std;

void make_adjList(unordered_map<int ,list<int>>&adjList,vector<pair<int,int>>&edges){
    for(auto i : edges){
        int u = i.first;
        int v = i.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(vector<int>&ans,unordered_map<int,bool>&visited,unordered_map<int ,list<int>>&adjList, int start){
    visited[start] = true;
    ans.push_back(start);

    for(auto neighbour : adjList.at(start)){
        if(!visited[neighbour])
            dfs(ans,visited,adjList,neighbour);
    }
}

vector<int>DFS(int  start , int vertices , vector<pair<int,int>>edges){
    vector<int>ans;
    unordered_map<int,bool>visited;
    unordered_map<int ,list<int>>adjList;

    make_adjList(adjList,edges);

    if(!visited[start]){
        dfs(ans,visited,adjList,start);
    }

    for(int i =0;i<vertices;i++){
        if(!visited[i]&&adjList.find(i)!=adjList.end())
            dfs(ans,visited,adjList,i);
    }

    return ans ;
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

    cout<<"Enter Start Node : ";
    int start;
    cin>>start;

    vector<int>result = DFS(start, vertices , edges);
    
    for(auto i : result)
        cout<<" "<<i;
    return 0;
}   