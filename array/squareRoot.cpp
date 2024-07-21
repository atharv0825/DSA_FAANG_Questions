#include<iostream>
using namespace std;

long long int SquareRoot(int n){
    int start = 0;
    int end = n;
    long long int ans =-1;

    while(start<end){
        long long int mid = start + (end - start)/2;
        long long int square = mid * mid;

        if(square == n)
            return mid;
        else if (square < n){
            ans = mid;
            start = mid +1;
        }    
        else {
            end = mid - 1;
        }

    }
        return ans;
}

double findPrecision(int temp , int n,int precision){
    double factor = 1;
    double ans = temp;
    for(int i =0;i<precision;i++){
        factor = factor/10;
        for(double j = temp;j*j<n;j = j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int temp = SquareRoot(36);
    cout<<temp<<endl;

    int temp1 = SquareRoot(37);
    cout<<" "<<findPrecision(temp,37,3);
}