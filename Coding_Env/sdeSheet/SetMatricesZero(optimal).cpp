#include<bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>>&v,int n,int m){
    // now we dont take any extra columns and row array instead we take the first row and first col to mark the rows and  columns
    //first row-> v[..][0]
    //first col-> v[0][..]
    // as the first cell will collide ,
    //step 1 : we traverse through whol matrix to check for zeroes , then according to thta we mark the ith row and jth col 
    int col0=1;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]==0){
                // mark the ith row 
                v[i][0]=0;
                //mark the jth col
                if(j!=0){  // when j is not equal=0  , because on v[0][0], the ifrst row marking an dcol marking collided so we made a col0 variable outside the matrix to store col0 marking there
                v[0][j]=0;  // so if col !=0 , then we will do normallly mark the jth col,but when the col is not ==0
                }  // we go to else part and 
                else{
                col0=0;  // we mark the variable as zero
              }
        }
    }
    }
    // step 2 now we start marking all non zero elemnts zero whose either co is marked or row is marked,
    // but we frst mark the matirx leaving the first row and first column , we start marking all other cells except the frst row and first col,
    //because if we marked it with these ellemnts then it might end up marking the first row , which will end up marking the whole first row as zero and hence would kead to incorrect output
    // so in order to avoid that we start marking it from beyond first row and first col
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(v[i][j]!=0){  // here we check for whichever ellents are non zero and we mark them 
                if(v[i][0]==0 || v[0][j]==0){
                    v[i][j]=0;  //here we check if ith row or jth colis zero we mark it as zero 
                    // otherwise if both are not marked we iterate further
                }
            }
        }
    }
    //so why did we not take into consideratio the col0 here in marking of ineer cells , because it is not needed , in marking of inner cells we dont need v[0][0], hence we dont need to check either for 0th row mark or 0th col mark
    // this will mark the inner part of matrix correctly leaving the first row and col alone
    // so now think what are we going to mark first ,first col or first row, if we mark the first row first theen we might end up adding zero in the v[0][0], which when we will check for the col ellemnts , if found zero all col ellemnts will be zero right, 
    //but when we first check for th col elemtns when will col elents be zero , when row[0][0]=0, which is not zero , so wemark it correcly 
    //when somethign is dependent on another thing , we first mark the thing that is dependent , so thta when we go fot the thing ehich was independnt , it will not create any error

    if(v[0][0]==0){
        for(int j=0;j<m;j++){  // mark the first col as zero 
            v[0][j]=0;
        }
    }

    if(col0==0){  // here we donot check orboth col and row because when col0 is zero , then even if row may nt be marked the marking will end as zero only for that particular row , because we need eiher col or row marked as zero not both
        for(int i=0;i<n;i++){
            v[i][0]==0;
        }
    }

   
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    solve(v,n,m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}