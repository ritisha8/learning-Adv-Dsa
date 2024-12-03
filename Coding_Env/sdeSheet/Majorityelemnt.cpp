// majority elemnt appears more than n/2 times 
// brute force would be to use map to store all the elelmnt frequencies and then return the ellemtn whose freqquency is greater than n/2;
// but that woukd takeextra O(n) space which we dont want
// tc of this solution is O(n), and SC: O(1)
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int> arr){
   int el;
   int cnt=0;
   for(int i=0;i<arr.size();i++){
    if(cnt==0){
        cnt++;
        el=arr[i];
    }else if(arr[i]==el){
        cnt++;
    }else{
        cnt--;
    }
   }
   cnt=0;
   for(int i=0;i<arr.size();i++){
     if(el==arr[i]){
        cnt++;
     }
   }
   if(cnt>arr.size()/2) return el;
   else return -1;
}
int main(){
vector<int>arr={1,1,1,2,2,0};
cout<<solve(arr);
return 0;
}