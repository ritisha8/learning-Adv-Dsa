//this is atype where we are given a row and col no. and we need to find the llemnt at that prticular row and col in pascal triangle
//in this type of question we can use the nCr formula of permutation and combinations , r-1
#include<bits/stdc++.h>                                                               //   C
using namespace std;                                                                  //    c-1    this is the formula that could be used here , in order to ftch the value
int elemnt(int row, int col){
    int res=1;
    for(int i=0;i<col;i++){   // running till col becaus we onlywant the elemnt till col places or whtver is the value ofcol, lets say col is 3 so we only want value of res to go till 3 places
       res=res*(row-i);   // so like in normal factorial, we do res= res*i,here we do res= res*(row-i),because we want to go till col plcaes or 3 places only so 1* 10- 0=10, 1* 10 -1=9, 1* 10-2=8;
       res=res/(i+1);     // then we compute the denominator, we dont compute it normally like 3* 2*1, because then 10/3 , would give us aprox value, which is not wat we want, so we start by 1 * 2*3,
       // then 10/1,would be something and then 10/1 * 9/2 , would get computed, because 2 will devide 10,then 10/1*9/2*8/3 woukd be something becausse 3 would dvide one of the 3 numbers
    }
    return res;
}
int main(){
    int r,c;
    cin>>r>>c;
    r--;
    c--;
    int res=elemnt(r,c);
    if(res==0){
        cout<<"invalid position of pascal triangle"<<endl;
    }else{
        cout<<"the elemnt at  row "<<(r+1)<< " and col "<<(c+1)<<" is "<<res;
    }
    return 0;
}