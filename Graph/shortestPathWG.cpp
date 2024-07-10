#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
    unordered_map<int, list<pair<int, int>>> adjList;

public:
    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdj() {
        for (auto i : adjList) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << " , " << j.second << "),";
            }
            cout << endl;
        }
    }

    void createGraph(int edgesCount) {
        for (int i = 0; i < edgesCount; i++) {
            int u, v, weight;
            cin >> u >> v >> weight;
            addEdge(u, v, weight);
        }
    }

    void dfs(unordered_map<int , bool>&visited,stack<int>&s,int node){
        visited[node] = true;

        for(auto neighbour : adjList[node]){
            if(!visited[neighbour.first]){
                dfs(visited,s,neighbour.first);
            }
        } 

        s.push(node); //nodes stored in the graph in the topological sort
    }

    void getShortPath(int start , vector<int>&distance ,stack<int>&s){
        distance[start] = 0;

        while(!s.empty()){
            int currentNode = s.top();
            s.pop();

            if(distance[currentNode] != INT32_MAX){
                for(auto i : adjList[currentNode]){
                    if(distance[currentNode] + i.second < distance[i.first]){
                        distance[i.first] = distance[currentNode] + i.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph g;

    cout << "Enter number of vertices: ";
    int vertices;
    cin >> vertices;

    cout << "Enter number of edges: ";
    int edgesCount;
    cin >> edgesCount;

    g.createGraph(edgesCount);
    g.printAdj();

    unordered_map<int , bool>visited;
    stack<int>s;

    for(int i =0;i<vertices;i++){
        if(!visited[i]){
            g.dfs(visited,s,i);
        }
    }

    cout<<"Enter starting node : ";
    int start;
    cin>>start;

    vector<int>distance(vertices);

    for(int i = 0 ; i<vertices;i++){
        distance[i] = INT32_MAX;
    }

    g.getShortPath(start , distance , s);

    for (int i = 0; i < vertices; i++) {
        if (distance[i] == INT32_MAX) {
            cout << "INF ";
        } else {
            cout << distance[i] << " ";
        }
    }
    cout << endl;
}
