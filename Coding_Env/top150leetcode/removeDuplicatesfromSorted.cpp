// brute force
#include<bits/stdc++.h>
using namespace std;
int removeDup(vector<int>&v){
   for(int i=0;i<v.size()-1;i++){  // less than v.size-1 because when it reahces v.size()-1 that is last element
    if(v[i]==v[i+1]){   // what will be the element after that none right? so it it could lead to seg fault, accessing a memory that is not there
        v.erase(v.begin()+i);
        i=i-1;
    }
   }
   return v.size();
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