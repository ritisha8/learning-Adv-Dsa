#include<bits/stdc++.h>
using namespace std;
vector<int> SortkSortedArray(vector<int>arr,int k){
      // we willl use min heap here because it will push a smallest element on top and then we can pop it out when it crosses k 
      vector<int>v;
      priority_queue<int,vector<int>,greater<int>>minh;
      for(int i=0;i<arr.size();i++){
        minh.push(arr[i]);
        if(minh.size()>k){
            v.push_back(minh.top());
            minh.pop();
        }
      }
    // after coming out of loop we have a vector storingall smaller lelemnts in sorted order other than 3 largest ellemnts
    //which are currently stored in heap smallest of 3 being at the top
    //so we empty the hap and push the lelment one ny one in vector when we pop one llement other ellemnt becomes top now it be smallest automatiaclly among the 2 left
    while(!minh.empty()){
        v.push_back(minh.top());
        minh.pop();
    }
    return v;
}
int main (){
    vector<int>arr={6,5,3,2,8,10,9};
    int k=3;
    vector<int>res=SortkSortedArray(arr,k);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}