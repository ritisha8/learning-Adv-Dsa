#include<bits/stdc++.h>
using namespace std;
vector<int> nextsmallertoright(int n,vector <int>arr){
    vector<int>v(n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){  //we started from n-1 u will get to know at the end why we did that
      while(!st.empty() && st.top()>=arr[i]){  // we check if stack is not empty and st top is more than or equal to arr[i]
        st.pop();   // if yes we do stack.pop so that the top will get popped and then loop will go again until either it gets empty or stack top becomes less than arr[i]
        // if either of the conditions turn true then loop will terminate
      }  // when we come out , we either have stack as empty or stack top < arr[i]
      if(st.empty()){  //  so we check if stack is empty if so 
        v[i]=-1;   // we do -1;
      }
      else{  // if not we come here
        v[i]=st.top();  // tehn we do  assign st.top to v[i] because now either stack top has become smaller than arr[i] after coming out of loop or
        // it is by default smaller than arr[i] from the start
      }
     st.push(arr[i]);
    }
    return v;
}
int main()
{
vector <int>arr={1,3,2,4};
int n=arr.size();
vector<int>res=nextsmallertoright(n,arr);

for(int i=0;i<n;i++){
  cout<<res[i]<<" ";
}



return 0;
}
