#include <bits/stdc++.h>
using namespace std;

void MakeAdjList(unordered_map<int, list<int>>& adjList, vector<vector<int>>& edges, int e) {
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v); 
    }
}

void dfs(unordered_map<int, list<int>>& adjList, unordered_map<int, bool>& visited, stack<int>& s, int node) {
    visited[node] = true;
    for (auto neighbour : adjList[node]) {
        if (!visited[neighbour]) {
            dfs(adjList, visited, s, neighbour);
        }
    }
    s.push(node);
}

void revDFS(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& transpose) {
    visited[node] = true;

    for (auto neighbour : transpose[node]) {
        if (!visited[neighbour]) {
            revDFS(neighbour, visited, transpose);
        }
    }
}

int findSCC(vector<vector<int>>& edges, int v, int e) {
    // Create Adjacency list
    unordered_map<int, list<int>> adjList;
    MakeAdjList(adjList, edges, e);
    
    // Topological sort
    stack<int> s;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++) {
        if (!visited[i])
            dfs(adjList, visited, s, i);
    }

    // Transpose of graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++) {
        visited[i] = false;  // Correction: Use false instead of 0
        for (auto neighbour : adjList[i]) {
            transpose[neighbour].push_back(i);
        }
    }

    // DFS on the transposed graph
    int count = 0;
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        if (!visited[top]) {
            count++;
            revDFS(top, visited, transpose);
        }
    }

    return count;
}

int main() {
    // Number of vertices
    int v = 5;
    
    // List of edges
    vector<vector<int>> edges = {
        {0, 1},
        {1, 4},
        {4, 0},
        {2, 3},
        {3, 2}
    };

    // Call the function to find the number of strongly connected components
    int noOfSCC = findSCC(edges,v,edges.size());

    // Output the result
    cout << "Number of Strongly Connected Components: " << noOfSCC << endl;

    return 0;
}
