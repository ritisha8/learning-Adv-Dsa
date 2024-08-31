#include<bits/stdc++.h>
using namespace std;
int removeElement(vector<int>v,int val){
    for(int i=0;i<v.size();i++){
      if(v[i]==val){  // while traversing if we find ellemnts equal to val we erase them 
        v.erase(v.begin()+i);  // when we erase thisway , thenect element to which ellemnt 
        //was erased, comes in its prev elemnt position because that address gets empty,and vector is contiguous,
        // so the next ellemnt fill it space
        // and so if we run the loop just after this i will point to next index whereas the nextellemnt is shifyed one place back
        //so that ellemt will be skipped  
        //in ordr to avoid that as soon as we erase the eleement we make the i pointer-- so that i now points to the eleemntprevious that what what was right now and
        // when it hits the forloop incrememnt now the element which was not traversing will be encountered
        i=i-1;
      }
    }
    return v.size();
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