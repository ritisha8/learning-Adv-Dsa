#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector <int>arr, int ele){
      int start=0;
      int end=arr.size()-1;
      while(start<=end){
        int mid=start+ (end-start)/2;
        if(ele>arr[mid]){
            end=mid-1;
        }
        else if(ele<arr[mid]){
            start=mid+1;
        }
        else{
            return mid;
        }
      }
      return -1;
}
int main(){
     vector<int>arr={20,15,10,5,4,2};
    int ele=5;
    cout<<"pos :"<<binarySearch(arr,ele);
    return 0;
}