#include<bits/stdc++.h>
using namespace std;
int binary1stOccur(vector <int> arr,int ele){
    int start=0;
    int end=arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(ele>arr[mid]){
           start=mid+1;
        }else if(ele<arr[mid])
        {
          end=mid-1;
        }
        else{
         res=mid;  // new mid we will store in res and 
         end=mid-1;  // and then assign check in left side if another if there is any other occcurance of 10 
         // then again whole binary search willl strt for that section and res will update its value if found ANOTHER 10
        }
    }
    return res;
}
int binaryLastOccur(vector <int> arr,int ele){
    int start=0;
    int end=arr.size()-1;
    int res=-1;
    while(start<=end){
        int mid= start +(end -start)/2;
        if(ele>arr[mid]){
            start=mid+1;
        }
        else if(ele<arr[mid]){
           end=mid-1;
        }
        else{
            res=mid;  // now store the mid in res if found equal to 10 , but we will also check in lest side if this is the last occurance 
            start=mid+1;  // thats why we did this
        }
    }
    return res;
}
int main(){
    vector<int>arr={2,4,5,10,10,10,15,20};;
    int ele=10;
    cout<<"1st occur:"<<binary1stOccur(arr,ele)<<endl;
    cout<<"last occur:"<<binaryLastOccur(arr,ele)<<endl;
    cout<<"count of 10 :"<<binaryLastOccur(arr,ele) - binary1stOccur(arr,ele) + 1;
    return 0;
}