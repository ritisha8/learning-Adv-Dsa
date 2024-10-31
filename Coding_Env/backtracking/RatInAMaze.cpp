//problem statemnet: there is a matrix , (consider it a cage where the rat is trapped) 
//given in wich some values are filled with 0 and some with 1, which indicates
// that wherever there is 1, rat can move from throught that path abd wheereevr there is
// 0 it cant go there , so wwe have to findto find te paths to free the mouse , and the muse 
//will be free when it reaches the (n-1,n-1) part in matrix. so there are certainconditions thta
// it cannot rpeatedly move to the same block it visited once and also it cant go to the areas where there is 0 value ,
// and if the first column where is he is 0 then it cant move it is trapped there and hence we return an empty vector

// APPROACH: so we have 4 choices here at evry stage , up , down , right,left, not evrrytime we have these choices , so we can cotrol recursion and prune some choices
// so it can be done with bakctraking ,just a thought we have large number of choices and they are variable , and they have to be conmtolled, so we can think ofusing balctraking
// so herewe go we know the basic format of bacraking allready ,so tis will be easy

// INPUTS: here we are given a function wih 2D vector and n, in which we need toreturn a vector <string> with all the paths 
// output : will be in the form of string wwhich contains the diff paths

#include<bits/stdc++.h>
using namespace std;
struct choice{  //this struct will defien each direction with its cordinates 
    char Dname;
    int dx,dy;
};
bool isSolved(int x,int y,int n){
    return x==n-1 && y==n-1;
}
bool isValid(int x, int y,int n,vector<vector<int>>arr){
    return x>=0 && x < n && y>=0 && y<n && arr[x][y]==1; // we know x and y avlue cant be neatueas the arry has positive indices in row and columns,and 
    //we know that wjereevr array has 0 values thta is not accessible , so we check if arr[x][y]=1
}
void solve(int x,int y,vector<vector<int>> &arr, int n,string &path, vector<string> &res, vector<choice>&choices){
    // bc
    // when x and y valuewill be n-1 , then we know we have reached our goal ,sowe stop there so that would be the base case
    if(isSolved(x,y,n)){
        res.push_back(path);
        return;
    }
    for(auto it=choices.begin();it!=choices.end();it++ ){   // run for loop for choices
        int newx=x+(*it).dx;   // now we make make changes in our new x and y's based on choice through struct 
        int newy=y+(*it).dy;
        // nowwe will controlwhich choiceisvalid and which is not 
        if(isValid(newx,newy,n,arr)){  // here we need a, y , arr for state checking u will see why we need n futher in function
           arr[x][y]=0;  // change x ,y block to 0sthat we dont come here in this block rpeatedly
           path.push_back((*it).Dname);
           solve(newx, newy,arr,n,path,res, choices);  // recursive call to further check for in which direction itcan go , with new x and y values
           //now revert backthe chnages or backtrak, so thta when nect choices it to be made , we have path string empty  for another iteration to find another path
           arr[x][y]=1;
           path.pop_back();
        }
    }
}
vector<string> RatInMaze(vector<vector<int>>arr,int n){
    vector<string>res;  // this vector wil store the ans all the combination of paths to reach the matrix end
    string path=" ";  // this will store eahc pathin each choice and it will be assed with ref , because this is themainvaribnale thta will be changing in 
    //backtraking andwe need to rever the change back i order to run the for loop for the next choice

    // then we need to make a struct to define the choices why? why cant we just define all teh choices in the vector and use it
    // because ith the up, down , right , leftwe alo need the x and y ,in order to make changes in row and xolumn metric of the matrix as we move forward towards any drection so thta we keep tarck of the path
    // so that we can check further in for loop at what point  which direction is relevant, because we need x , y and matrix to check for state of a block whether it is blocked or not
    //so we define a struct choice and then we make a vector of choice objects to stoe all the different objects of struct
    vector<choice>choices={{'U',-1,0},{'D',1,0},{'R',0,1},{'L',0,-1}}; //here we define eahc cpr ordinae and how they weill chnage if the rat moves in eahc of the direction
     if(arr[0][0]==1){
       solve(0,0,arr,n,path,res,choices); // now we decide whteeer things we want in order forit to work
     }
     return res;
     
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>arr(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<string>v=RatInMaze(arr,n);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it;
    }
    return 0;
}