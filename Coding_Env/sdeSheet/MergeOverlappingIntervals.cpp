// TC: here we tarversed each element twice , so the complexity would be nlogn for sort and O(2n) for tarversal
// Intuition: first we sorted the array, beacuse in order for merging the intervals , it needs to be in sorted 
// order, so tat the next greater interval is next to it, and it is easier to merge, for easier merging we
// perform sorting, to bring the lelmnts to be merge closer to each other, sorting does that for us
// step 2: create an ans 2d vector to store the result, then we iterate through all the llemnts one by one
// the outer loop will iterate all the intervals one by one , then , when we are on an interval , we check
// for the i+1 intervals till n , if their first elemnt or v[j][0] is less than the 2nd elelmnt of the i being traversed or v[i][1]
// if yes, we change the 2nd ellemnts range by selecting the maximum from both either v[j][1],or v[i][1] whichever is maximum is storedin v[i][1]
// then we move to another iteration and then if the ans is not empty and the current interval's[i][1] is less than or equal to previous ans.back()[1], 
//then its allready trversed and hence we dont take it into acccoutn and continue to the next iteration
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> solve(vector<vector<int>>&v){
    // sort the array
    sort(v.begin(),v.end());
    int n=v.size();
    vector<vector<int>> ans;
    //now travesing 
    for(int i=0;i<n;i++){
        int start=v[i][0];
        int end=v[i][1];
        if(!ans.empty() && end<=ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(v[j][0]<=end){
                end=max(v[j][1],end);
            }else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>>ans=solve(v);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}