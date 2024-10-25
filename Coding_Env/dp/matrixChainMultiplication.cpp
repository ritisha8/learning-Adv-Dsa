//basic format of mcm and identification , so whenever we see a question in which by assigning and i to leftmost index and j to rightmost index , when we break the array or string with a k in between , and te solution is somwhow visualizable ,then it is matrix chain multiplication question
// its format is 
//step 1 : finding the correct i,j 
//step 2 : defining base condition
//step 3 : find the k loop scheme
//main step: decide for the induction step to complete the function
// here in this question we need to find the minimum no. of mutliplications while multiplying crtain matrices, we have to find out which way of mutlipying them would bring out the minimum cost or minimm no. of mutliplaications
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];// usually defined from the constarints by choosing the at the maximum size of array an dadding one to it 
int solve(vector<int> arr, int i , int j){
   // step 2: BC
   if(i>=j){  // i>j is a format for this mcm , but we have added one change to it , i.e i>=j which meand when i is equal to j , then array ellemnt will be only one , so then also matrix formatio is not quite pissible
   //and when i>j then size of array ecomes zero then also matrix cant be formed
    return 0;  // when i>j and i==j , then matric cant be formed hence , minimum no. of matrix multiplications zero
   }
   if(t[i][j]!=-1){
    return t[i][j];
   }
   int mn=INT_MAX;
   // step2 done
   // k loops scheme
   for(int k=i;k<=j-1;k++) {// k=i;k<=j;k++  this is the basic format of writing k loop scheme we have to make changes to it according to our qeustion , so here lest check k for evry i and j when k=i , one partiton will be
   // arr[0]*arr[1] and another k+1 to j, in this way different combinations will be formed in order to find the minimum no. of multiplications, with each iteration k will  divde into two matrices i to k, and k+1 to j,  
 // but here the in the format there will be slight change thta would be lets check when k =j then i to k will be whole array i to j and there willnot be any k+1 to j marix to divide,so we need to run our loop till j-1
 // so that when k is j-1 , one combination will be upto j-1 and another would be k + 1 to j;
   int temp=solve(arr,i,k)+solve(arr,k+1,j)+ arr[i-1] *arr[k]* arr[j]; //this is because when a mtrix arr[i-1]*arr[i] will be done,and then arr[i]* arr[k] will be two of the subproblem then 
    // this ishowwe find outthe total cost by calculting the cost of ito k , adn then k+1 to j and then the cost of muliplying both of these matrices together;
   mn=min(mn, temp); //this we do in order t find the min of the total cost and store it in in mn
   } 
   return t[i][j]=mn;  // then we store the min value in t[i][j] and them return the minimum
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(t,-1,sizeof(t));
    int i=1;  // because matrix is formed with arr[i-1] * arr[i] , when i is 0 , arr[i-1] ill be -1 which is not an index , so we take a valid i thta is 1 , hen a matrix ispossible arr[0]*arr[1];
    int j=arr.size()-1;  // for j lets see if the same matrix formation works well, arr[j-1]* arr[j] , we can do this without any error right? j-1 would be the second last ellemnt and , j would be 
    //last , so they will tgether form a matrix and index is nowheere going out of bounds , so it is valid
    // total number of matrces thta can be formed = sizeofARRay -1;
    // 1st step is done, finding valid values of i and j 
    cout<<solve(arr,i,j);
    return 0;

}