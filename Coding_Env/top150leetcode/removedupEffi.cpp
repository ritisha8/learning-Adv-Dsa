//a better approach to remove duplicates using sets
#include<bits/stdc++.h>
using namespace std;
int removeDup(vector<int> &v){
    set<int>st;
    for(int i=0;i<v.size();i++){
        st.insert(v[i]);
    }
    int index=0;
    for(auto it=st.begin();it!=st.end();it++){
        v[index]=*it;
        index++;
    }
    return st.size();
}
int main(){
    
    int n;
   
   cin>>n;
   vector<int>v(n);
  
   for(int i=0;i<n;i++){
    cin>>v[i];
   }
   cout<<"after removing duplicates"<<removeDup(v)<<endl;
   for(int i=0;i<removeDup(v);i++){
    cout<<v[i]<<" ";
   }
   
  return 0;
}
