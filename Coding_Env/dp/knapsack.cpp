#include<bits/stdc++.h>
using namespace std;
int t[100][100];  // for this we check constraints and take +2 or +1 value matrix than defined in contarints because we also want to include the base case in matrix 
// here first 100 defines items and another capacity
int knapsack(vector<int> wt,vector<int> val,int W,int n){
    // here we first come up with a recursive solution and then memorize it to make it dp
   
    // base case we knpow we calculate base case according to leats valid input
    if(n==0 || W==0){  // if items are zero then whtevr maybe capacity then maximum prfit will always be zero
                      // of it capacity of knapsack is 0 hen no matter now many items we have we cant put in it so max pofit again 0; least valid input would be this only
        return 0;
    }
     //how dowe do recursion? by making input small? where we need to do recrusion, wherever there are choices abd we need to make a decision
    // hee we have choices whether to out an item in knapsack or not accordign ot its weight , we made a decsion tree according ot that if wt ofitem is more than knapsack cap, then ofc it will not be included, if wt of item is less than or = Cap then we have 2 chocies whther toincludde it or not 
    // remember how we did in sorting array mid of stack , we make input small by taking the alste llemt out and then storing it somewhere  doign a  recursibve call for reduced input , here we dothe same 
    // we jsut dont eliminate last elemnt directly we make a decsion for the last eelemnt whther to include it or not according to decison tree
    //now we memorise it , memorise means we will store it in matrix in order to store the output of recrusive call, so that if the same rec call is made in any other part of recusrive tree then it it will just take value form the matrix andf then extra overhead will be reduced
    if(t[n][W]!=-1){  // we check now if there is -1 then this condition doesnt execute and recursive call is made noramlly and ans is stored in 
    // but if t[n][W]!=-1 then it must contain max profit of same recursion call that happened before and then we just simply return it
        return t[n][W];
    }
    if(wt[n-1]<=W){  // here we check if wt of item is smaller than cap
        return t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));  // then we took two choices one of including val[n-1], when we include n-1 in knapsack then ofc its cap for further checing will decrease because that space is occupied by the wt of this elemnt we chose , and another choice we make of not inluding the ellemtn and just dogn a recyrsive call for n-1 elelmtns , and now we put bothinto max function , because we want o return the ,ax profit , as we have two choices the ,ax of 2 will be returned
    }
    if(wt[n-1>W]) //then we check if  weight of n-1 ellemtns is greater than cap then, simply dont include the eelemnt swe simply make a recursie call to one choicethatw e have not nt including
    {
        return t[n][W]=knapsack(wt,val,W,n-1); // 
    }
}
int main(){
    int W;  // capacity
    cin>>W;
    vector<int> wt={4,5,1};  //wt of items
    vector<int> val={1,2,3};  // val of items
    int n=wt.size();  // items
    memset(t,-1,sizeof(t)); //setiing all values in t matrix as -1;  we will see why further
    cout<<knapsack(wt,val,W,n);
    return 0;
    
}