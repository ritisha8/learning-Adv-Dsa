#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n<=1){
        return n; // base case
    }
    return n*fact(n-1); //hypothesis plus induction
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}