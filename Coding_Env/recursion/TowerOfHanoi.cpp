#include<bits/stdc++.h>
using namespace std;
// whenever we dont understand what to do in a recursion prob we do it by ibh method
// where i means induction,b base case, h, hypothesis , in this we first design hypothesis and then we perform inductyion that is whtever needed to complete the function
// then we find the base case , base case is the least valid input 
void toh(int n,int s,int d,int h){
    //base case  , what could be ther leasr valid input here , when disc is only 1
    if(n==1){
        cout<<"move disc "<<n<<" from rod "<<s<<" to rod "<<d<<endl; 
        return;
    }

   // so we are designing a hypothesis first for this prob, we are given a function toh(n,s,d,h) with parametres as n that is the no. of discs and s is the sourse rod and h is the helper rod and
   // d is the destination rod and now this function will successfully shift  n discs from source to destination and will print the steps the output opf this function is steps and input is n, so it will work same for n-1 discs as well
    //toh(n-1,s,d,h); if we do like this it will shift n -1 discs from rod 1 to rod 3 and thelast rod n which is left in rod 1 and which is bigger than all these if we put it above these rods in rod 3 it will voilate the rule of tower of hanoi
    // so we do
    toh(n-1,s,h,d);   // so we will move n-1 discs from rod 1 to rod 2 that is helper rod first and then we will move the nth disc in rod 1 to directly to dest rod
    cout<<"move disc "<<n<<" from rod "<<s<<" to rod "<<d<<endl;  // induction step to compelte the fucntionn , we moved n-1 rods to helper rod and now here the nth rod we will move to dest rod
    //now we move n-1 rods from helper to dest
    toh(n-1,h,d,s);  // this step will move n-1 rods from helkper to destination rod now everythinf is done 
    return;
}
int main(){
    int N;  // will input no. of discs
    cin>>N;
    int s=1;   // source rod
    int h=2;   //helper rod
    int d=3;   // destination rod
    toh(N,s,d,h);
    return 0;
}