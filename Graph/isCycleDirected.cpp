#include<bits/stdc++.h>
using namespace std;

void make_adjList(unordered_map<int,list<int>>&adjList , vector<pair<int,int>>&edges){
    for(auto i :edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
    }
}

int isCycle(int vertices , vector<pair<int,int>>&edges){
    //1.make Adjacency list
    unordered_map<int , list<int>>adjList;
    make_adjList(adjList ,edges);
    //2.make indegree list
    unordered_map<int , int>indegree;

    for (int i = 1; i <= vertices; ++i) {
        indegree[i] = 0;
    }


    for(auto node : adjList){
        for(auto neighbors : node.second){
            indegree[neighbors]++;
        }
    }
    //make queue add the nodes who's indegree is 0
    queue<int>q;
    for(int i =1;i<=vertices;i++){
        if(indegree[i] == 0)
            q.push(i);
    } 

    //to check how many nodes we traversed if count is not equals to the no. of vertices it means cycle is present
    int count = 0;
    //perform BFS traversal
    while(!q.empty()){
        int currentNode = q.front();
        q.pop();

        count++;

        for(auto neighbors : adjList[currentNode]){
            indegree[neighbors]--;
            if(indegree[neighbors] == 0){
                q.push(neighbors)   ;
            }
        }        
    }

    if(count==vertices)
        return 0;
    else   
        return 1;    
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
 
    int result = isCycle(vertices ,edges);
    if(result)
        cout<<"Yes";
    else   
        cout<<"No";
    return 0;
}   