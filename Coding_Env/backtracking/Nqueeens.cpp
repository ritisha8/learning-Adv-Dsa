#include<bits/stdc++.h>
using namespace std;
bool check(int colidx,int rowidx,int n, vector<vector<int>>board){
    //for left side
    for(int col=0;col<colidx;col++){
       if(board[rowidx][col]==1){
        return false;
       }
    }
    //for diag1
    int i=rowidx,j=colidx;
    while(i>=0 && j>=0){
       
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }
    // for diag2
     i=rowidx, j=colidx;
    while(i<n && j>=0){
       
        if(board[i][j]==1){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
void solve(int colidx,vector<int>&temp,vector<vector<int>>&ans,int n,vector<vector<int>>board){
    //base case  
    if(colidx==n){     // when colidx reaches n thta is after the last column is traversed, then we push whteverr value we have in temp to it
        ans.push_back(temp); 
        return;
    }
    for(int rowidx=0;rowidx<n;rowidx++){  // what all choices do we have for each column , 0 to n rows right?,where we can put our queen
        if(check(colidx,rowidx,n,board)){    // now we put a check onthe choices whichever ones are valid will enter inside the curly braces
                                            // and whicever are not valid , next iteration next choice will be taken 
            board[rowidx][colidx]=1;  // if the choice is found valid , we put it onthe rowidx and colidx in board
            
            temp.push_back(rowidx+1);  // beacuse we have to return 1 based index ans  ,and thenpass it position in temp

            solve(colidx+1,temp,ans,n,board); // then we call for the next column to get the whole combination for further columns

            board[rowidx][colidx]=0;  //then we bakctrack once this call finishes and it comes back and we revert the changes and 
            // wheveer we stored 1 for fixing queen position ,so that

            temp.pop_back();  // then we popback(); temp so that now we can explore all further choices at eahc recursive call and add it to temp.
        }
    }
}
vector<vector<int>> Nqueens(int n){   //because we are given nothing in question except n that is size of matrix 
    vector<vector<int>>ans;  // this is forstoring the ans , this 2vector will storeallthe combinations we gathered thrpugh bactraking

    vector<int>temp; //this is the main variable that will be passed as reference and will be changed at each point in recursion, and 
    //when a call finishes and comes bakc ,it is backtracked and then used for furthe combinations

    vector<vector<int>>board(n, vector<int>(n,0)); //so we need to make a 2d gridof n*n ,as the question specifies grid willonly be n*n
    solve(0,temp,ans,n,board); //as we do col by col traversalhere , as we need toretur the plces where queen is put in each column ,
    //sowe pas here colidx,and the ref varible (main) tem,ans for storing all temp combinations, 2d grid, from which we will traverse 
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>v=Nqueens(n);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}