#include<bits/stdc++.h>
using namespace std;
//why would ans have only 2 ellments because you see , if size of vector is 6 , n/3 would be 2, so we need ellemtn size min to be 3 right? to be greater than 2, yes
// so lets se how many elemtns can we have of 3 size in 6 size array , 3+3 , only 2 right , we cant have not even a single one at all.
//so only  elemnt at max,we an have in 6 size array, lets see in 8 size array, n/3 would be 2, so here if we do 3+3+3 exceeeds the size fo array right after adding the last 3
// now lets see with 9 , n/3 is 3,so 4 size count we need min , 4+4+4 is not possible only 2 4s are possible after that it would cross the count
vector<int> solve(vector<int> &v){
    vector<int> ans;
     for(int i=0;i<v.size();i++){
        if(ans.size()==0 || ans[0]!=v[i]){   
            // if ans size is 0 or ans first ellemt is not equal to v[i], 
            //we check the whole array if for teh coutn of v[i], other wise we just sip the iteration if the ans size is neither 0 nor its first eleltn is!=v[i], which menas if foudn equal we skip the oteration
            // because ans will have only 2 elemnts,we dont want the same elelmnt in the ans, so the elmnt for whom we have counted allaredy and allredy taken in ans, we skip the iteration.
          int cnt=0;   // then we are chechking for count here so we make cnt as 0 
          for(int j=0;j<v.size();j++){// then for counting we run a j loop 
            if(v[i]==v[j]) cnt++;  // we tarverse from the start if v[i] == v[j], simply increment the count
          }
          if(cnt > (v.size()/3)){  // after one checking of whole array is done for gettign coutn
          // we check if the count is found after traversing the whole array is greater than n/3 if yes, add it to teh ans vector
            ans.push_back(v[i]);
          }
        }
        if(ans.size()==2) break;  // an after each iteration i is done we check whenevr ans ectr size turns 2 we break out of loop , becausew we dont need to check further this is teh ans
     }
     return ans;
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    vector<int>m=solve(v);
    for(int i=0;i<m.size();i++){
        cout<<m[i]<<" ";
    }
    return 0;
}

