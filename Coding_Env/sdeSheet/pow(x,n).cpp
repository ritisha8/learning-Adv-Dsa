#include<bits/stdc++.h>
using namespace std;
double solve(double x, int n){
    int nn=n;
    double ans=1;
    if(n<0) n=n*-1;
    while(n>0){
        if(n%2==1){
            ans=ans*x;
            n=n-1;
        }else{
            x=x*x;
            n=n/2;
        }
    }
    if(nn<0) {
        ans=1/ans;
    }
    return ans;
}
int main(){
    int n;
    double x;
    cin>>n;
    cin>>x;
    cout<<solve(x,n);
    return 0;
}