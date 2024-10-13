#include<bits/stdc++.h>
using namespace std;
int t[11][51];   // according to constraints 
int solve(int e, int f){
    //base case
    if(f==1|| f==0){
        return t[e][f]=f;  //if floor =0; , no of ways the egg can be used before getiing threshhold is 0 and when f=1no. of ways the egg can be used before getting threshold is obviously one
    }
    if(e==0) return t[e][f]= 0;
    if(e==1){
        return t[e][f]=f;  // if egg=1 , then inworst case it can go from first floor without breaking to the fth floor, sowe need toreturn the no. of ways in wprst case so return f
    }
    if(t[e][f]!=-1){
        return t[e][f];
    }
    //basee case done
    int mn=INT_MAX;  //beacuse we need to fin the minimum no. of ways
    for(int k=1;k<=f;k++){
        int left,right;
        if(t[e-1][k-1]!=-1){
             left=t[e-1][k-1];
        }else{
            left=solve(e-1,k-1);
        }
        if(t[e][f-k]!=-1){
            right=t[e][f-k];
        }
        else{
            right=solve(e,f-k);
        }
        int temp=1+max(left,right);  //we have taken maximum of when egg will break and when it will not because we want to return the worst case, so
        // we have added one in order count the attempts , one attempt is allready done here ,at this k, and as we move further in subproblems another attempts will be addedd
        mn=min(temp,mn);
    }
    return t[e][f]=mn;
}
int main(){
    int f;
    int e;
    cin>>f>>e;
    memset(t,-1,sizeof(t));
    cout<<solve(e,f);  // here we definei j as the first and last elemnt of floor  
    return 0;
}