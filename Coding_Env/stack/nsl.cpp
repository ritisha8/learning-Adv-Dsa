#include<bits/stdc++.h>
using namespace std;
vector<int> nextsmallerToLeft(int n, vector <int>arr){
    vector<int>v(n);  // take a vector to store nearest smaller elemnts of the vector given in params
    stack<int>st;  // take a stack to store all left elements
    for(int i=0;i<n;i++){  // starting from frist elemnt, we run a loop till less than n
        while(!st.empty() && st.top()>=arr[i]){  // first we will check if stack is not empty and st top is >= arr[i]
            st.pop();  // if ys, we do st.pop(), and again check condition until stack has become empty or stack top has become less than arr[i]
        }  // now after coming out , either stack is empty or stack top is less than arr[i]
        if(st.empty()){  // if stack is empty we return -1 in v[i]
            v[i]=-1;
        }
        else{   // if not then stack top has  become less than arr[i]
          v[i]=st.top();  // then we assign stack to to v[i]
        }
        st.push(arr[i]);  // now push the arr[i] into stack
    }
    return v;
}
int main(){
vector <int>arr={1,3,2,4};
int n=arr.size();
vector<int>res=nextsmallerToLeft(n,arr);

for(int i=0;i<n;i++){
  cout<<res[i]<<" ";
}
return 0;
}