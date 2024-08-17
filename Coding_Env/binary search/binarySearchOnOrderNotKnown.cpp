#include<bits/stdc++.h>
using namespace std;
int decendingBinary(vector <int>arr,int ele){
  int start=0;
  int end=arr.size()-1;
  while(start<end){
    int mid=start + (end-start)/2;
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
int  ascendingBinary(vector <int> arr,int ele){
   int start=0;
  int end=arr.size()-1;
   while(start<end){
    int mid=start + (end-start)/2;
    if(ele>arr[mid]){
        start=mid+1;
    }
    else if(ele<arr[mid]){
        end=mid-1;
    }
    else{
        return mid;
    }
   }
return -1;
}
int binarySearch(vector <int>arr,int ele){
      if(arr.size()==1){
        if(ele==arr[0]){
            return 0;
        }else{
            return -1;
        }
      }
      else if(arr.size()>1){
        if(arr[0]>arr[1]) {
            return decendingBinary(arr,ele);
        }
        else{
            return ascendingBinary(arr,ele);
        }
      }
}

int main(){
    
    vector<int>arr={20,15,10,5,4,2};
    int ele=10;
    cout<<"pos :"<<binarySearch(arr,ele);
    return 0;
}