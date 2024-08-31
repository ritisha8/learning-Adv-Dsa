//recursive approach // not at all efficient but i m just trying to solve vevry questio with recursion
#include<bits/stdc++.h>
using namespace std;
int removeDup(vector<int>&v){
   if(v.size()==1){
            return v.size();
        }
        
        int temp=v[v.size()-1];
        v.erase(v.begin()+v.size()-1);

   removeDup(v);
   if(temp==v[v.size()-1]){
    return v.size();
   }
   else{
    v.push_back(temp);
    return v.size();
   }
}
int main(){
    int n;
   cin>>n;
   vector<int>v(n);
  
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   removeDup(v);
   for(auto i=v.begin();i!=v.end();i++ ){
    cout<<*i<<" ";
   }
   
  return 0;
}