//TC: O(log base 2 (n+m)) * O(m+n) for the inner loop 
// whenever the ierations are getting divided by2 we take the tc as log base 2 with whtever is the lenght of array , sowe took O(log base 2 (n+m))  this
// then we have another inside loop which traverse each elemnt , maybe not inone go , but approximately we can say that it traverse each ellemnt so, the tc can be O(m+n)
// sowehave the time complexity as this
#include<bits/stdc++.h>
using namespace std;
void swapGreaterToleft(vector<int>&arr1,vector<int>&arr2,int idx1,int idx2){
  if(arr1[idx1]>arr2[idx2]){
    swap(arr1[idx1],arr2[idx2]);
  }
}
void solve(vector<int>&arr1,vector<int>&arr2,int n,int m){
    int len=n+m;
    int gap=gap/2 +gap%2;  // so that when n+m is odd it divide by 2 and mod of odd number is 1 so 1is added to it and hence the cieling value is taken
    while(gap>0){
      int left=0;
      int right=left+gap;
      while(right<len){
        //in arr1 and arr2
        if(left<n && right>=n){
          swapGreaterToleft(arr1,arr2,left,right-n); // why right -n because when right will be in second array its actual position insecond array will be right-n
        }
        //in arr2 and arr2
        else if(left>=n){   //as left is ineft right will also be in left otherwise it be out of bounds
        swapGreaterToleft(arr2,arr2,left-n,right-n);  // now bothleft and right -n because both are in second array so both  index will be left-n and right -n
        }
        //in arr1 and arr1
        else{
         swapGreaterToleft(arr1,arr1,left,right);  // if both are in first array then no need of right -n and left -n because index values allign with the actual values of right and left
        }
      }  // this loop will run until the right goes out of bounds 
      if(gap==1) break; // then as soon as the right goes out of bounds the gap wil be updated to half 
      gap=gap/2 + gap%2;  //then aggain lft and right are assigned newly according to gap values then inner loopruns until agagin right goes out of bounds,
      // untilthe gap value is 1 all the steps are repeated to put each of the elelmtn at its correct place
    }
}
int main(){
    int n,m;
cin>>n>>m;
vector<int>arr1(n);
for(int i=0;i<n;i++){
  cin>>arr1[i];
}
vector<int>arr2(m);
for(int i=0;i<m;i++){
    cin>>arr2[i];
}

solve(arr1,arr2,n,m);

for(int i=0;i<n;i++){
  cout<<arr1[i]<<" ";
}
cout<<endl;
for(int i=0;i<m;i++){
    cout<<arr2[i]<<" ";
}
return 0;
}
