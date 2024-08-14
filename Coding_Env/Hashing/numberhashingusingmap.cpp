#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    //hashing using map
    map<int,int>mp;// map data structure stores elements in key value pairs so if we take array elements as key and their occurances as value
    for(int i=0;i<n;i++){   // we run a loop to traverse the array
        mp[arr[i]]++;      // here we do thsi because, if try to fetch the value of mp[arr[0]], lets say arr[0]=4, it will return ans as 0;because it has no element i it until now
    }    // then if we do mp[arr[0]]++ , now it stores 4 in it as key and 1 as its value (that is occurance), like this if we do 
    //mp[arr[1]]++ it will store the array elelmnt as key and it occurance as its value.
    

    int q;
    cin>>q;
    while(q--){
      int num;
      cin>>num;
      //fetching
      cout<<mp[num];  // mp[num] will return the corresponding value of key =num, it will return its value.
      
    }
    return 0;
}