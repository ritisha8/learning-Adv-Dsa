//brute force approach which takes time complexity O(N^2)
#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int> v,int t){
    for(int i=0;i<v.size();i++){ // we will check for every i if thereis any ellemnt whose sum with i makes t, 
        for(int j=i+1;j<v.size();j++){  // we willl start j with i+1 because the previous eelemnts sum we have alrready checked for then only we moved forward
            if(v[i]+v[j]==t){
                return {i,j};
            }
        }
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