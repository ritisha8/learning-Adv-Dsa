#include<bits/stdc++.h>
using namespace std;
vector<int> KClosestElement(vector <int>arr,int k, int x){
    // we will make a max heap of pair type for this so that all the larger keys will be pushed to top and we will pop them if they are more than k
    priority_queue<pair<int,int>>maxh;
    vector<int>v;
    for(int i=0;i<arr.size();i++){
        maxh.push({abs(arr[i]-x),arr[i]});  // we will store (arr[i] -x )in key and that is the difeerence from x of aaray ellemt the lesser the difference the closer they are to x
        // and in value we will store array element
        // lets say first elelmnt was 1  and x is 3 so we do 1 - 3 =-2 , -2 will be stpred as key and 1 will be stored as value
        // noe we check after pushing as usual 
        if(maxh.size()>k) {// if found more than k we simply pop
             maxh.pop();
        }
    }
    // after coming out of this loop we have key value pairs in maxh with highest key at the top and others might not be in a sorted order
    // 1 as key and 4 as value  but other might not be in sorted order, so we puhs them in vector one by one
    while(!maxh.empty()){
        v.push_back(maxh.top().second);  // now 4 will be pushed into vector
        maxh.pop();                      // (1,4) will be popped
        // now we check if maxh is empty if not this process repeats and now the largest key will eb pushed to top automatically and then we push its value into vector , 
    }
    //now we have to sort teh vector because it will not store th closeset ellemnt in sorted order
    sort(v.begin(),v.end());  // we use C++ stl to sort
    return v;
}  
int main(){
    vector<int>arr={1,2,3,4,5};
    int k=4;
    vector<int>res=KClosestElement(arr,k,3);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}