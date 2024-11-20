//tyep 3 is where we need to printthe whole triangle,here aslo we can us ethat nCr formula like we did in tyep1 
//for(i-> row){
//    for(col->i{
//       nCr(i-1,col-1);       // now this will return the corrrct ans, but lets see the time complexity here,     
//    }} 
// TC: O(row)*O(row)*O(i)   which would be nearabout or lets take the worst case O(n^3), so now lets optimize it
//how can we do that , we know we did the type 2 in O(n) , we genertaed each row in O(n), so when n rows need to be genratd, then TC will be O(n) *O(n) =O(n^2)
#include<bits/stdc++.h>
using namespace std;
vector<int> generateRow(int row){
    vector<int>temp;
    long long ans=1;
    temp.push_back(ans);
    for(int col=1;col<row;col++){
        ans=ans*(row-col);  // when we compute the col by 0 based indexing
        ans=ans/col;
        temp.push_back(ans);
    }
    return temp;
}
int main(){
int r;
cin>>r;
vector<vector<int>>ans;
for(int i=1;i<=r;i++){
    ans.push_back(generateRow(i));
}
for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
return 0;
}