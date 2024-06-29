#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
#include<list>
using namespace std;

void make_adjList( unordered_map<int,list<int>>&adjList,vector<pair<int,int>>&edges){
    for(auto i : edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
    }
}

void dfs(stack<int>&s , unordered_map<int,bool>&visited,unordered_map<int ,list<int>>&adjList, int start){
    visited[start] = true;
    for(auto neighbour: adjList[start]){
        if(!visited[neighbour])
            dfs(s,visited,adjList,neighbour);
    }
    s.push(start);

}

vector<int>topologicalSort(int start,int vertices,vector<pair<int,int>>edges){
    unordered_map<int,list<int>>adjList;
    unordered_map<int,bool>visited;
    stack<int>s;
    make_adjList(adjList,edges);
    
    if(!visited[start])
        dfs(s,visited,adjList,start);
        
    for(int i =0;i<vertices;i++){
        if(!visited[i]&&adjList.find(i)!=adjList.end())
            dfs(s,visited,adjList,i);
    }
    vector<int>ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

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

    cout<<"Enter Start Node : ";
    int start;
    cin>>start;
 
    vector<int>result = topologicalSort(start, vertices , edges);
    
    for(auto i : result)
        cout<<" "<<i;
    return 0;
}   