// the brute force apppraoch to this question would be to sort the array and return the value at 4th place , that would be 4th smallest elemnt
//but brute force takes time complexity O(nlogn) , the most efficient sorting algo merge sort takes O(n logn) so we can do it in O(nlog k) time by 
//using a heap, there is an identification of heap , wherever there is k and smallest/largest in question we use heap there, 
// if smallest we use max heap, if largest we use min heap.

#include<bits/stdc++.h>
using namespace std;
int kthSmallestElement(vector<int>arr, int k){
     // lets take max heap, we take max heap in smallest because max heap tends to bring the largest element on the top while inserting elements into it
     priority_queue<int>maxh;  // max heap declaration
     for(int i=0;i<arr.size();i++){  // we will run  a loop to traverse vector
        maxh.push(arr[i]);     // first we willl push the frist ellemnt in max heap 
            if(maxh.size()>k){   // then we will check at evevry step of insertion if maxheap size is more than k
               maxh.pop();  // whenever it is found more than k we can safely pop it; because that is a larger number than 4th largest which is of no use to us
            }
     }// after coming out of loop our max heap will have kth smallest ellemnt as it top because all elelmnts larger than kth we popped
     return maxh.top();  //sowe return maxh.top() 
}
int main(){
    vector<int>arr={8,6,5,9,3,10,2};
    int k=4; 
    cout<<kthSmallestElement(arr,k);
return 0;
}