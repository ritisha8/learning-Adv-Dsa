//k sorted array is when an array elements original sorted position lies in its next k places either left or right
//brute force would be to simply sort the array which takes O(nlogn) but we ill do it in O(logk) using heaps
#include<bits/stdc++.h>
using namespace std;
vector<int> SortkSortedArray(vector <int>arr,int k){
    // here we ill us emin heap , so that all smalller ellemnts come on top and we will push it into vector and tehn pop it from heap
     vector<int>v;
     priority_queue<int,vector<int>,greater<int>>minh;
     for(int i=0;i<arr.size();i++){
        minh.push(arr[i]);    //pushing into min heap arr[i]
        if(minh.size()>k){// if min size is more than k
            v.push_back(minh.top());  // then insert into vector and pop from heap
           minh.pop();
        }
     }// now after comign out our vector will have some sorted elments in it , the remanining greater k greater lelmnts willbe in heap
     while(!minh.empty()){
         v.push_back(minh.top()); // because it will contain smallest at top so in order to get it in sorted order we pop it 
         minh.pop();    // and then the procss repeats and we get another top ellemnt which is smallest of the remaining , it will repeat until heap is empty
     }
     return v;
// top 3 ellemts will be stored in mih heap and other smallers ones will be moved to vector in ascesdinh orde because if we push 3 th
     
}
// remember what we did before in kth lagest and kth smallest , by pushing in heap we also sorted them till that kth elemnt, like in maxheap in smallest kth we had all the largest ellement popped and we had only first smallest hat is the smallest, 
//and 2nd 3rd and 4th smallest in maxh, so when we were finding the kth ellemnt he heap stored k ellemtns larger than that or k elemnts smaller than that , minheap k larger and in max heap k smaller
//then here also if we use min heap we get for ar[i] all k ellements larger than that stored in it and the smaller ones we can simply pop out one by one but after storing in vector.
int main(){
    vector<int>arr={6,5,3,2,8,10,9};
    int k=3;
    vector<int>res=SortkSortedArray(arr,k);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}