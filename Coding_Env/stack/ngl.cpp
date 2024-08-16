#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterToleft(int n,vector<int>arr){
  stack<int>st;
  vector<int>v(n);
  for(int i=0;i<n;i++){
    while(!st.empty() && st.top()<=arr[i]){
        st.pop();
    }
    if(st.empty()){
        v[i]=-1;
    }
    else{
        v[i]=st.top();
    }
   st.push(arr[i]);
  }
  return v;
}
int main(){
    vector<int> arr={1,3,2,4};
    int n=arr.size();
    vector<int> res=nextGreaterToleft(n,arr);

    for(int i=0;i<n;i++){
       cout<<res[i]<<" ";
    }
    return 0;
    
}
