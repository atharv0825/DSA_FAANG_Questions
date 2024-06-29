#include<iostream>
#include<vector>
#include<map>
#include <unordered_map>
#include <list>
using namespace std;


void addEdges(unordered_map<int,list<int>>&adjL,int u , int v , bool direction){
    adjL[u].push_back(v);
    if(direction == 1){
        adjL[v].push_back(u);
    }
}

int main(){
    cout<<"Enter the number of edges : ";
    int e;
    cin>>e;
    cout<<"Enter the number of nodes : ";
    int n;
    cin>>n;
    unordered_map<int,list<int>>adjL;
    for(int i =0;i<e;i++){
        cout<<"Enter (u -> v) = 0 (v -> u) = 1 : "; 
        int u,v;
        cin>>u>>v;
        addEdges(adjL,u,v,0);
    }

    for(auto i : adjL){
        cout<<i.first<<"-> ";
        for(auto j : i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}