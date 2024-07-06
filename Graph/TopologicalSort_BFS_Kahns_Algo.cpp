#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<list>
#include<algorithm>
#include <unordered_set>
using namespace std;

void make_adjList( unordered_map<int,list<int>>&adjList,vector<pair<int,int>>&edges){
    for(auto i : edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
    }
}


vector<int>bfs(int vertices,unordered_map<int ,list<int>>&adjList){
    //calculate indegree
    vector<int>inDegree(vertices + 1, 0);
    for(auto i : adjList){
        for(auto j : i.second){
            inDegree[j]++;
        }
    }
    queue<int>q;
    for(int i =1;i<=vertices;i++){
        if(inDegree[i] == 0 && adjList.find(i) != adjList.end()){
            q.push(i);
        }
    }

    vector<int>ans;
    //Do actual BFS here
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();

        ans.push_back(currentNode);

        //Traverse neighbors of the current node

        for(auto neighbour : adjList[currentNode]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    return ans;
}

vector<int>topologicalSort(vector<pair<int,int>>&edges){
    unordered_map<int,list<int>>adjList;
    make_adjList(adjList,edges);
    unordered_set<int> nodes;
    for (auto& edge : edges) {
        nodes.insert(edge.first);
        nodes.insert(edge.second);
    }
    int vertices = *max_element(nodes.begin(), nodes.end());
    vector<int>result = bfs(vertices,adjList);
    return result;
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

    
 
    vector<int>result = topologicalSort(edges);
    
    for(auto i : result)
        cout<<" "<<i;
    return 0;
}   