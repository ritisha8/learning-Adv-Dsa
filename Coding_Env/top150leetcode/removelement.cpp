#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>&v,int val){
    int index=0;
    for(int i=0;i<v.size();i++){
        if(v[i]!=val){
            v[index]=v[i];
            index++;
        }
    }
    return index;  // at last when all elemnts wil be finished index will be one extra because weare incrementing it each time non equal elent is foud so index remains always 1 greater than the ellemnts inserted not equal to value

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