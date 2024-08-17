// the brute force apppraoch to this question would be to sort the array and return the value at n-k place , that would be 4th largest elemnt
//but brute force takes time complexity O(nlogn) , the most efficient sorting algo merge sort takes O(n logn), so we can do it in O(nlog k) time by 
//using a heap, there is an identification of heap , wherever there is k and smallest/largest in question we use heap there, 
// if smallest we use max heap, if largest we use min heap.
#include<bits/stdc++.h>
using namespace std;
int kthLargestElement(vector<int>arr,int k){   // here we will use min heap beacause min heap tends to give the top ellemt as minimum
//so we can remove allthe smaller ellemnts from top
        priority_queue<int,vector<int>,greater<int>>minh; // declared min heap
        for(int i=0;i<arr.size();i++)  // we wil traverse the array now 
        {
            minh.push(arr[i]);  //inserting arr[i] in min heap which will automatically place largest ellemnts at botom and smallest at top
              // now we will check if minh size is more than k at every step of traversal 
              if(minh.size()>k){
                  minh.pop(); // if found more than k , we simply pop the llemnt , because we dont need the elemtn, as it is a smalller value than
                  // the 4th largest which we dont need , we only need first largest second largest 3rd largest and 4th largets in heap  , 
                  //any value smaller than 4th largest is not required by us or lets say 5th largest is not requird by us
              }
        }
        //after coming out of  loop minh will contain top ellement as kth largest ellemnt , so we do
        return minh.top();  // it will reurn the kth largest ellemnt , because now our heap comtians only 1st 2nd 3rd 4th lrgest , 
        //all other llemnts more than k we popped. now we know min heap contains smallest value at its top ,other might not
        // be in order but smalllest is at top ,  so the smallest of these 4 would be 4th largest oly right because 1st largest would be largest of the whole arrray 

}

int main(){
    vector<int>arr={8,6,5,9,3,10,2};
    int k=4; 
    cout<<kthLargestElement(arr,k);
return 0;
}