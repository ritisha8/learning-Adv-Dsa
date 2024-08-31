#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>&v,int val){
    if(v.size()==1){
            if(v[0]==val){
              v.erase(v.begin()+0);
            }
            return v.size();
        }
        int temp=v[v.size()-1];
        v.erase(v.begin()+v.size()-1);
        removeElement(v,val);
        if(temp==val){
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
  int val;
  cin>>val;
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  int index=removeElement(v,val);
  cout<<"no. of elelemnts after removing:"<<index<<endl;
  for(int i=0;i<index;i++){
    cout<<v[i]<<" ";
  }
  return 0;
}