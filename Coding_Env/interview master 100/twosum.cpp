// leetcode optimal solution O(nlogn) because we are using map here , unordered map would result in O(N) in avg and best case but O(n^2) in wosrt case , the find function that we will use here might take the wordt case time complexity to find the element, so we avoid unordered map
//space complexity would be O(n) because we are storing the llemnts in hashmap
// we could also use 2 pointer but it is only optimal when we have to return yes /no or true false
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v,int t){
    //create a hashmap to store the array elemnts withtgeir indices
    map<int,int >mp;
    //traverse and check if the complemmnt of the current elemtn exist in map , if yes returnnthe index corresponding to it and the current elemnmt index a, otherwise just store the ellemnt in map and increment
    for(int i=0;i<v.size();i++){
        int num=v[i];
        int comp=t-num;
        
        if(mp.find(comp)!=mp.end()){  // if found 
            return {mp[comp],i};  // return the complement index and current elemnt index which is i
        }
        mp[num]=i;
    }
    return {};
}
int main(){
   int n;cin>>n;
   vector<int>v(n);
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   int t;
   cin>>t;
   vector<int>v1=solve(v,t);
   if(v1.size()==0){
    cout<<"{}";
   }else{
      for(int i=0;i<v1.size();i++){
         cout<<v1[i]<<" ";
        }
   }
   
   return 0;
}


