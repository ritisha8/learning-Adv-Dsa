#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>arr){
    int start=0;
    int end=arr.size()-1;
    int min=INT_MAX;
    while(start<=end){
        int mid= (start+end)/2;

        if(arr[mid-1]<arr[mid]){
            min=mid-1;
            end=mid-1;
        }else if(arr[mid+1]<arr[mid]){
            min=mid+1;
            start=mid+1;
        }else{
            
        }
    }
}
int main(){
    vector<int>arr={15,20,2,4,5,10};
    
    cout<<"No.of Times rotated :"<<binarySearch(arr);
    return 0;
}