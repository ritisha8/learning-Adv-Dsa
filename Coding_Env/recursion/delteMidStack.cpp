#include<bits/stdc++.h>
using namespace std;
void solve(stack<int>&st, int k){
    if(k==1) {   // k ==0means we have no middle an sowe cant delte it so that would be invalid input
        st.pop(); //whenk is1means we have only 2 ellemnts in stack so mid==1 mean top element in stack
        return;
    }
   //hypothetucally it will delte the mid ellemtn so when we dont know what todo we makeinput smaller, here inputwe have taken a stac and a mid ellemnt
   // if we remove the lastelemnt of stack that is top ellemtn then if k remains the samethen it willend up deleteing the wrong mid ,so ifstack size dec by 1 ,middle will also get dec by 1
   //then k will also decrease which was k earlier willbe k-1 now , we have to delt the kth elemtn from the top so when we dec the size of stack by 1,then k will also decrease by 1 right which was k ,as we dont wanto change k  we do this
   int temp=st.top();
   st.pop();
   solve(st,k-1);  // this will delee the mid from decreased stack hypotheticlly,the midellemnt this dec stackand originalstack is same ,so nowwejust have topush the last elelmntback because we got our ans
   st.push(temp);  //now we need to push the ellemnt removed from it
}
int main(){
    stack<int>st;
    st.push(50);
    st.push(10);
    st.push(20);
    st.push(40);
    st.push(30);
    int k= (st.size()/2)+1;   // midddle pos
    solve(st,k);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}