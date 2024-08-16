#include<bits/stdc++.h>
using namespace std;

vector<int> nextgreaterToright(int n,vector <int>arr){
   vector <int>v(n);  // we make a vector to store the nearest greater ellemnts in this vector of n size , the same size as the array is given to us so that it doesnt fall out of bounds
   stack<int>st;  // this stack is for pushing nearest ellemnts to left into it
   for(int i=n-1;i>=0;i--){
    // we will check if sstack is not empty and stack top is less than arr[i],
     while(!st.empty() && st.top()<=arr[i]){
        st.pop();  // then we pop() until stack is empty or until stack top becomes more than arr[i];
     }
     //now after coming out of while loop either stack would have become empty or stack top has become more than arr[i];
     // now we check if stack is empty
     if(st.empty()){
        v[i]=-1;   // if stack is found empty we assign v[i] -1 , either stack could have been empty from startign or it became epty after while then also it will jump to this if
     } // now if stack is not empty then obviously the other condition might have been turned false thats why it came out of while loop
     else{
        v[i]=st.top();  // so we do v[i] = st.top(), because now st.top has become more than arr[i], evem if a condition would be that stack top greater than arr[i] frothe start ,
        // it will fall here because this is the last else where every codntion other than the above two will fall
     }
     // now we push arr[i] into stack;
     st.push(arr[i]);
   }
   return v;
}
int main(){
vector <int>arr={1,3,2,4};
int n=arr.size();
vector<int>res=nextgreaterToright(n,arr);

for(int i=0;i<n;i++){
  cout<<res[i]<<" ";
}



return 0;
}