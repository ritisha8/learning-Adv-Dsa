// here we first  see the range in which the s1 and s2 exists and then we derieve equation like we know s1 + s2=sum(arr[i]),so we put the valu of s2 from here in another equation
//where we have s2-s1=minimize; here we put that and get sum-s1-s1=minimize, sum-2s1=minimize and hence w need to minimize this now, 
// now we jsut get the sumof array and run the susbet func fucntion to get the last row of dp matrix , becaus the last row of matrix contains the range of sums which are possible to become s1;
//then we put the last row of dp matrix in vector , or we ust extract itys sum and use it to minimize the equation we got ,

// why we took the subet sumof whole array sum beacuse when array elemnet , beacuse we wanted to know which sum's partion are possible from the whole range , an dthen we wanted to put the values of sums we found out in place of s1 inthe
// formula,we calculated , which is the sumof one partion, when we minusthe sumof array with 2 oduble of suj of 1 partion we get , thta is the value we need to minimize , as as we donot have another partion here so we have to make use of whtever valeus we have and derieve an equation 
// from there we can either store the j values or sum valeus in vector nand then further minimize the equation we got inthe beginning min=sum-2s1, sum - jo bi s1 or j ki values hmne find out kri with the last column of dp matrix
#include<bits/stdc++.h>
using namespace std;
int solve1(vector<int> &arr,int n,int sum){
    int t[n+1][sum+1];  // created dp matrix
    for(int i=0;i<n+1;i++){   // filled the first row and first columns of matrix
        for(int j=0;j<sum+1;j++){
            if(i==0){
                t[i][j]=false;  // if i==0 means array is empty, so if sum kis more than 0 , it cant be formed right? so it is false, even when sum is 0 we are doing it false for now , we will further override it with true
            }
            if(j==0){  // if j==0  , if sum==0 , then array size may any from 0 to n, one empty subset is always possible
                t[i][j]=true;  // so we do true wherever j==0 
            }
        }
    }
    for(int i=1;i<n+1;i++){   // here we fill the remaining matrix
        for(int j=1;j<sum+1;j++){
            if(arr[i-1]<=j){   //here we make descion for i=1 and j=1 if we should include arr[i-1] in subset sum or not , 
            //in each state array will be true or false ,so we do put or between them so that if one true exists then ,it wil return true to t[i][j]
                t[i][j]=t[i-1][j-arr[i-1]]|| t[i-1][j];
            }
            else{// if arr[i-1]>j  then we simply dont include it
                t[i][j]=t[i-1][j];
            }
        }
    }// now we take an elemnt to store the min 
    int mn=INT_MAX; // we make it int max so that the first elelmnt it get in loop it will be definately smaller than this max so that will be assigned to mn then

    // see nowwhy we did it , because we are totalyy clueless abotu how to calculate the subet parttions in anarray, we take a range of values that can be valueif partionns,
    //so  the minimumvaklue of partion can eb empty vector , and highst value of a parttion wouldbe full complete array, we nowknow our bothof the vectors lie in this rnage, when array is empty sum is 0,and when array is fullsum is sum of array
    // so now we know our partion values lie between 0 and sum of arrray, now lets say ths is the array [1,6,11,5], now we know sum 0 is possible , sum 1 is possible , sum 2 isnot posssible from this array ,is it?,itis not , so we find the subset sum of th wholesum of array , 
    //and on the last row we will get for which values, subset sum is possible from 0 to the sumdefined and sum we defined as teh sum of whole array right?, so then we find of the min, value at that particular j ,or sum value whereever subset sumis possible, and we calculate d the minimum value to be 
     for(int j=0;j<sum+1;j++){
        if(t[n][j]==1){
           mn=min(mn,abs(sum-2*j));
        }
     }
     return mn;
}
int solve(vector<int>&arr ,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
    }
    return solve1(arr,n,sum);
}
int main(){
   int n;
   cin>>n;
   vector<int>arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<solve(arr,n);
   return 0;

}