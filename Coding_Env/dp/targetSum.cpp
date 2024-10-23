// this is absolutely same as count of partitions with agiven difference, just the question is a little twisted , here we are given a +, and - sign and we can put it on any array ellemnts in order to get the target , 
// so what we will do is just , in countof partition , we were given difference right , and we wanted to count the parttions that will form that difference, so we can say that there s1-s2 =diff was given , here s1 is sum of parttion1 and s2 sum of partition 2
// so what we did there was get the first parttion and then and then we performed subet sum count,find how many sinsets can be formed whose sum1 will be what we will find out now, so if sum1 count was something its obvious , the other partition sum would be sum2 , if first partion sum is s1, as they both are made from sum of array
// so let see how we got the s1 value, , we knw s1-s2 , diff was given in prev question right? here also he target is the differnece only because we have two signs positive and negative and when we addd them there will be definately a diff that comes out to be target , as the signs are opposite , if the sign was all positive then we could say it is a sum.
// so we are given s1-s2=diff, and we know s1+s2=sumofArray, now we will add these two equations and we get 2s1=sumOdarray+diff, so s1 value we get as sumOfArray+diff/2
//now we will find out the subset sum count of this s1 and whtever will be the count of this will be the answer of this question, what we needed to get was in how many way can we array the + and - sign in order to get the target,and now when weget the count of s1 , we know that if sumcount we got s2 count will be same as if sum1 count we gotweknow both 
//sumof toatl sum of array so if first part sum is s1  and we git count of that then def whenvwr s1 was found s2 would be nothing but s1-diff, because we want to the equation given in question.


//here we treat target as diff because there has to be atleats one negative sign in the xpression thta we want to create , right? 
//so that will create it a difference onkly, so we treat it as a different and then we find outthe count of partions with this difference , thats what we want here,
// we have to put + - sign in away thta two partions create this given difference, how do we calculate that lets see , have we done any related question to this , 
//think about it , is there any questionwe worked with difference of two partions , yes we did, in the ocunt of artion with a given difference,

// we want to find thta hm iss exprssion ke kitne ways me partions bna skte jo ki hme yhi same diff ya target de hmesha
//dont you thinkit is kind of or exactly similar to the question we did, there we just separated the partions fromthe array and then found out the diff, here we need to create an expression, which we donot need to do it practically
// ,logicaly if we divide th arry ionto two parts in order to crate the diff and find out how many ways thta difference is calcualted then also e get its ans right ,we can do it in thta way as well right, ray into different partions thta form the difference  and calculate how many times same diff occured, right?
#include<bits/stdc++.h>
using namespace std;
int solve2(vector<int>arr,int n,int sum){
    int t[n+1][sum+1];
    memset(t,0,sizeof(t));
    /*for(int i=0;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            if(i==0){
                return 0;
            }
            if(j==0){
                return 1;
            }
        }
    }*/ // we will not do it this way because it possible that array elemnt is 0 , then when sum is 0 then there will be two subets {},{0}
   t[0][0]=1;
   for(int i=1;i<n+1;i++){
    for(int j=0;j<sum+1;j++){
        if(arr[i-1]<=j){
            t[i][j]=t[i-1][j-arr[i-1]] +t[i-1][j];
        }else{
            t[i][j]=t[i-1][j];
        }
    }
   }
   return t[n][sum];
}
int solve(vector<int>arr,int t,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    if((sum+t)%2!=0){
        return 0;    // as we want a whole no. here in order to get s1 partiton if sum+diff turn out to be odd it not possible to divide it by 2 and hence 
    }
    else{
        return solve2(arr,n,(sum+t)/2);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    cout<<solve(arr,t,n);
    return 0;
}