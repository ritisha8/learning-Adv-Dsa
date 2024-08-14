
//this is hashing usimg array. but it is not prefereable method to hash , because it take time complexity of O(N *Q) where q is
// the number of queries and n is size of array , if we have both size as 10^7 which is maximum, it will be O(10^7 * 10^7)  which is O(10^14), 10^8 takes 1 sec of time, so it will end up taking 2 sec
//which os not at all efiicient , mostly efficient algorithms take 1 sec or less, so we use map instead of this approach
#include<bits/stdc++.h>
using namespace std;
// max size of array that we can atek globally is 10^7, whereas max size in main is 10^6, so if we have 10^18 capacity we have map data structure for that
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //hashing 
    int hash[13]={0};    // taken a hash array with all values as zero
    for(int i=0;i<n;i++){  // here we run a loop for all array ellements till n
      hash[arr[i]]++;     // lets say arr[0]=2; then hash[arr[0]] will be hash[2],then we do 
      //hash[2]++,as we are storing  all elemnts in sequential order so hash[2] elemnet will be 2 whici is previously 
      //zero and then we did hash[2]++, so now it is 1, which means 2 is occyuring one time in array, lets say we got 2 again
      //at a[4]=2;then hash[2] which is 1 will become 2 after incrementing, now we know 2 is ocurring 2 times in array. 
      
    }

    int q;
    cin>>q;
    while(q--){
      int num;
      cin>>num;
      //fetch
      cout<<hash[num];
    }
 return 0;
}
