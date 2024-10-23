// here we want s1-s2=diff , like we wanted s1-s2=0 in equal sum partition , and like we did in min subset sum s1-s2=minimize
// here we have 1 equation which is given in question , and we can frame another equation by , we know s1+s2=sum(arr[i]);
// so we add boththese equation and we get 2s1=diff+sum; so s1=(diff+sum)/2; if we get sum of first partition ,we can simply so susbetsum with this sum to checkif it exist because if it does , then definatey another partion s2 which is s1-diff will also exist


#include<bits/stdc++.h>
using namespace std;
int count(vector<int>&v,int n, int sum){
    int t[n+1][sum+1];
    memset(t,0,sizeof(t));
    // here we dont deal with base cases similarly because as we did when sum is 0, we did return 1 for all array sizes but , we didnt take into cosnideration if array ellemnt turns out to be zero , then there will be two susbets , {} {0} , one mepty and one with 0 in it so here we  dont just thoughlessly give 1 in base condton we check for j=0 same as we check for ellements from j=1 to sum+1;
    // but we make the first elemnt of t[0][0] as 1, becauase  it will remain 1 only it will only have an empty subset only beacuse when vector size is zero and partition size is zero,
    t[0][0]=1;
    //we are not calcukating for the first row when vector size=0 , and sum=0 ,then absolutely the when vector size would eb zero and sumwould be anything we cant calulte soteh ans will be 0, and zero we allerady placed in the whole matrix as default in memset.
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){  // because we dont know here if sum =0 ,will have how many values it can alsohave zeroes in it as elemnt right, so weadd it here to compute it like rest of the other
            if(v[i-1]<=j){
                t[i][j]=t[i-1][j-v[i-1]] + t[i-1][j];
            }else{
                t[i][j]=t[i-1][j];
            }
        }
    }
   return t[n][sum];
}
int solve(vector<int>&v,int n,int d){
    int sum=0;
    for(int i=0;i<n;i++){// first we calculate sum throug this loop 
    sum=sum+v[i];
    }
    if((sum+d)%2!=0){  // then we need to check if the sum+diff is off then its prtition if got divided by 2 it will not be a whole numnber and  we want the parttion in int as whole number ,so we return 0 because if it is odd our equation that we got will not be satisfied
        return 0;
    }else{  // if sum+d is even then we take return count function where we check if that partition exists in vector v and if it does for how many times
        return count(v,n,(sum+d)/2);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int d;
    cin>>d;
    cout<<solve(v,n,d);
    return 0;

   
}