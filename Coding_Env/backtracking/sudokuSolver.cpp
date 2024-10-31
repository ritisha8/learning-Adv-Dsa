#include<bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>>&v,int rowidx,int colidx,int num){
    //checkfor the row
    for(int j=0;j<9;j++){
        if(v[rowidx][j]==num){
            return false;
        }
    }
    // for col
    for(int i=0;i<9;i++){
        if(v[i][colidx]==num){
            return false;
        }
    }
    // for grid 3 X 3
    int sr=(rowidx/3)*3;
    int sc=(colidx/3)*3;
    for(int i=sr;i<sr+3;i++){
        for(int j=sc;j<sc+3;j++){
            if(v[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
bool solve(vector<vector<int>>&v,int rowidx,int colidx){
    if(rowidx==9){
        return true; // when rowidx reaches 9 we will have our ans so we are returning true
    }
    if(colidx==9){
        return solve(v,rowidx+1,0);   // when colidx reaches 9 after mutiple ccalls to the next cell , hen we call the next row 
    }
    // base case done

    // if there is allready an elemnt in matrix , or it is prefilled cell , simply skip it, and move to the next cell
    if(v[rowidx][colidx]!=0){
        return solve(v,rowidx,colidx+1); 
    } 
    // if the cell is empty or 0 
    //main part
    for(int i=1;i<=9;i++){  // here we are going to takewhtever choices we have regardless of which one is valid ornot , we simply give eahc choice a chance first
    // then we make a checker function to checkif th taken choice is valid according to the row , col, grid
    if(check(v,rowidx,colidx,i)){
        v[rowidx][colidx]=i;// if the choice is valid or true for the cell we store the choice in that particular cell, if not we move to the next iteration of for loop and check other choices 
        bool res=solve(v,rowidx,colidx+1);
        if(res) return true;
    }
    }
    // so there will be times when you reach a cell where no choice from 1 o 9is valid , that means ,we have taken wrong choices somewhere in revious recursive calls;
    // sothen when all choices are traversed and not any is valid for cell the control comes ouof forloop and then we amke thta cell into 0 its original value and then we return false, 
    // now when the recurisve call returns false here , it not go into if condition and it will check for further choices of that particular call from where it left off after those all
    // choices will be explored , if we explore one choiceand itis valid , but futher in further rec call it appers to be invLID,THEN ANOTHER ITERTION IS DONE FOR FURTHER CHOICE AND
    // THE VALUE OF v[i][j] is overrided with all the valid values until all choices are explored and then we move out of loop when all choices are exhausted 
    v[rowidx][colidx]=0;
    return false;

}

int main(){
    vector<vector<int>>v(9,vector<int>(9,0));
     v = {
       {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
     };


    solve(v,0,0);

    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<v[i][j]<<" ";
      }
      cout<<endl;
    }
    
    return 0;
}