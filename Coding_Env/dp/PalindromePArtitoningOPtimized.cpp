//we need to find the fewest number of cuts needed to for palinfrome partioning
#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
bool ispal(string s, int i, int j){
    while(i<=j){
        if(s[i]==s[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    return true;
}
int solve(string s, int i, int j){
    // base condition
    if(i>=j){  // here also we need to make thta one change , because when i crosses j thta means string is empty now , 
    //when i and j are same then string has only one letter, when there isonly one letter, no partition can take place right?
        return 0;  // also when there isno elemnt string is emptythn also no partion can take place as it is allready
    }
    if(ispal(s,i,j)==true){
        return 0; // when string is palindrome, we return 0, because we want o find the minum no. of parttions in order ot perform palindrome partitioning , when string is laready a palindrome , the minimu no. of partions needed to make it make it aplindrome string ,would be 0
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    int mn=INT_MAX;
    int left, right;
    //base condition done
    for(int k=i;k<=j-1;k++){  // here we are dividing the whole string with k , one part from i to k another form k+1 to j  , in ordr to have smaller subproblems arather than a whole big one
   // so when k==j then one division would be from i to k thta would be then i to j , but then thre will not be any k+1 to j , so another partiion might not be possible thre, so we need to 
   //so we move k till j-1
   // here in optimized verison we check if the subproblem,s have already been solved or not , and if they have we take a=their value and use it otherwise we compute their value through recursive call and save it in the subprobem cell in matrix
    if(t[i][k]!=-1){
        left= t[i][k];
    }else{
        left=solve(s,i,k);
        t[i][k]=left;
    }
    if(t[k+1][j]!=-1){
        right=t[k+1][j];
    }else{
        right=solve(s, k+1,j);
        t[k+1][j]=right;
    }
    int temp=solve(s,i,k)+solve(s,k+1,j)+1; // this solve function wil return the min no. of partions in i to k and in k+1 to k , as we have allredy made one partion here, by divind into smaller subprobelms so 1 will be added to both of the subprobems solutions
    mn=min(mn, temp);
    }
    return t[i][j]=mn;
}
int main(){
    string s;
    cin>>s;
    int i=0;  // here i can be zero , thre wont be any problem in thta because in prev problemwe had to multiply matrices , so mtrix formation was an issue 
    int j=s.length()-1;  // corectly the rightmost index 
    memset(t,-1,sizeof(t));
    // i j defined
    cout<<solve(s,i,j);
    return 0;
}