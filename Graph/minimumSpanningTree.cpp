#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}

void make_set(vector<int>&parent,vector<int>&rank,int n){
    for(int i =0;i<n;i++){
        parent[i] = i;
        rank[i]=0;
    }
}

int findParent(vector<int>&parent , int node){
    if(parent[node] == node)
        return node;

    return parent[node] = findParent(parent,parent[node]);
}

void unionSet(vector<int>&parent , vector<int>&rank , int u , int v){
    u = findParent(parent,u);
    v = findParent(parent,v);

    if(rank[u]<rank[v]){
        parent[u] = v;
    }else if(rank[v]<rank[u]){
        parent[v] = u;
    }else{
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>rank(n);
    vector<int>parent(n);
    make_set(parent , rank , n);

    int minWeight =0;

    for(int i =0;i<edges.size();i++){
        int u = findParent(parent , edges[i][0]);
        int v = findParent(parent , edges[i][1]);
        int w = edges[i][2];

        if(u != v){
            minWeight += w;
            unionSet(parent,rank,u,v);
        }
    }
    return minWeight;
}

int main() {
    int n = 5; // Number of vertices
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 3, 8},
        {1, 2, 3},
        {1, 4, 5},
        {2, 4, 7}
    };

    int minWeight = minimumSpanningTree(edges, n);

    cout << "The weight of the minimum spanning tree is: " << minWeight << endl;

    return 0;
}