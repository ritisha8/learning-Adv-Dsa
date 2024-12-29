#include<bits/stdc++.h>
using namespace std;
void insert(int temp, stack<int>&st){
    // THIS IS ALSO A RECURSIVE FUCNTION WE COULD MAKE IT ITERATIVE BUT WE ARE CURRENTLY LEARNING RECURSION SO WE ILL DO IT BY RECURSION
    // bc till when this fucntion fill make inputs smaller until the stack is empty or it has 1 elemmtn , no we can pop it even in 1 ellemnt so we take an dempty stack after this pop() on empty stack will be ibnvalid
    if(st.size()==0 || st.top()<=temp) {
        st.push(temp);
        return;
    }
    // HYPOTHETICALLY IT WILL PLACE THE TEMP INTO ITS CORRECT POSITION SO WHEN WE DONT KNOW WHAT CAN WE DO , WE SIMPLY MAKE THE INPUT SMALL
    int val=st.top();
    st.pop();  // re,ogved the last ellemnt and stored it in a variable
    insert(temp,st);  // now we assu,me this fucntion will simply isnert the temp at its correct position  now we need tot hink till when this recursive call wil run , till which least valid input 
  // after inserting at its correct position we have to insert the popped ellemnt at its correct pos
  st.push(val);
}
void sort(stack<int> &st){
// we have to return a sorted stack heree
// base conmdition
// what would be the least possible valid input of the sort fucntion in stack , 1 elemt right? 0 ellemnts would mean no sorting so that would be invalid input
if(st.size()==1) return ;  // id stack has onlyone elemnt it is allready sorted so we illl simply return the stack 

// lest design hjypothesis if stack has 4 ellemts currecntly and we remove the last ellemt and store it in a vruiable and then call the sort function agagin now theb asort function will work properly 
// and it will return thje sorted stack and now we ill just need to insert the last llement that we popped  at its correct position
int temp=st.top();
st.pop();
sort(st);
insert(temp,st);  // induction step

}
int main(){
    stack<int>st;
    st.push(50);
    st.push(10);
    st.push(20);
    st.push(40);
    sort(st);   // we know that this function takes a stack as input and is going to return a sorted stack
    // so this is hypothesis it will work same if reduce stack size by 1 i.e make input smaller so lets see in the sort fucntion now
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}