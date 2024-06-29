#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


// int N , E ;//Node - N and Edges - E

void createAdjacency(vector<vector<int>>&adj , int arr[][2] , int N , int E){
    for(int i = 0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            adj[i][j]=0;
        }
    }

    for(int i =0;i<E;i++){

        int x = arr[i][0];
        int y = arr[i][1];
        
        adj[x][y] =1;
        adj[y][x] =1;
    }
}

void printAdjacency(vector<vector<int>>&adj , int N){
    for(int i =0 ;i<N+1;i++){
        for(int j =0;j<N+1;j++){
            cout<<" "<<adj[i][j];
        }
        cout<<endl;
    }
}

int main(){
    //no of vertices
    int N = 5 ;

    int arr[][2] = {
        {1,2},{2,3},
        {4,5},{1,5},
        {4,1},{4,2}
    };

    int E = sizeof(arr)/sizeof(arr[0]);

    vector<vector<int>>adj(N+1,vector<int>(N+1));
    createAdjacency(adj,arr,N,E);
    printAdjacency(adj,N);
    return 0;

    
    
}