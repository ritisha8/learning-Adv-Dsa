//here we need to generate the whole row of the pascal traingle which is given in input, so can u do that?
//yes likewe generted each ellemnt before in typ1 we can generate each ellemnt of te row in that way and then we can put it in for loop which runs till row no.
// like ans=1; for(int i=0;i<row;i++){     // this is for each col , i is the col here, so the columns will go till  rownumber as we have observeed
//     ans=funcnCr(row-1,i-1);  // as i is the column  ,this takes O(i)
//     print(ans);
// 
//  }     this is the brute force ,what is the time complexity it is taking here, O(row) or O(n) *O(i), which is not good , lets try to improve it
// another method would be derieved by understanmding the pattern in the ans, like in 6th row we have , 1 5 10 10 5 1, so lets find the pattern,
// we know like if we start col from0 based index, in this row, then we can write 5/1, and then 10/2 now 10/2 doesnt computes to 10 , 
//lets see we have 5/1 from prev , 5/1 * wjhat do we need to make it 10 we know here the dvision will be 2, at evry step column no. would be divided,
// so we what is left 5*1/2 , what could be added to make it 10,= 4 , that is 6-2, so 5*1/2*6 (that is row no.) -col no., now we get 5*1/2*6-2/2 =10, 
//now in next row also same patern is foolowed , 10/3 * 6-3, that is 10

#include<bits/stdc++.h>
using namespace std;
void generateRow(int row){
    int ans=1;
    cout<<ans<<" ";
    for(int col=1;col<row;col++){
        ans=ans*(row-col);  //6-1= 5
        ans=ans/col;    // 5/1 =5 
        cout<<ans<<" ";
    }
}
int main(){
    int r;
    cin>>r;
    generateRow(r);
    return 0;
}