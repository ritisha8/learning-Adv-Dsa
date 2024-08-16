#include<bits/stdc++.h>
using namespace std;
// we only change the push function here  because we know in queue isnertion happens fromone end and deletion happens from another so pop will happen from front here usually like it happens , but now 
// we change the push which happens from back it should happn from first as well , then it will become a stack.
struct Stack{  // created a structure named stack
    queue<int>q1,q2;   // we dididnot take any size capacity like we did in queuue because queue we wwere implementing in queue only here we are implementing stack using queue not its own ellemnts, so why do we need to take stack elements.
    int top(){  // here we used queue stl  and this is top() fucntion  stack top should return the topmost ellemnt
        return q1.front();   // here we do q1.front() and not back because we did we know deletionin queue hapens from front by default , so we did implemented push from front as well
        // so if pop and push are hapening from front so the top should be taken from front only , consider it a reversed version of stack
    }
    void pop(){ // here  we pop like usually we do in queue
        return q1.pop();  // this will pop the front element ,and it is okay for us because we are implementing push also from 
        //front here, so it remains stack only , we know in stack insetion and deletion happens from one end only, that rule follows here
    }
    int size(){ // here we dolike ususally we do in queue stl implementation
        return q1.size();  // we return the q1 size like ususal.  we are going to use 2 queues to implement stack but we are going to give the result in q1 only.
    }
    void push(int x){  // here we know normal push operation in queue happens from back , but we will perform it from front u will see how
        while(q1.empty()==false){  // frist we run a loop till q1 gets empty
          q2.push(q1.front());  // we tranfer the front ellemtn of q1 to q2 back , until noe q2 was empty
          q1.pop();  // then we pop that front element, and this process repeats until queue1 is empty
        }
        q1.push(x); //  now when q1 is empty we push the given elemnt into it 
        while(q2.empty()==false){  // now we run a loop till q2 is empty
         q1.push(q2.front());   // now we push q2 front ellemtn at back  of q1, and we know q1.push will push q2.front()ellemtn in back of q1
         q2.pop();  // now we pop the elemtn from q2. we know pop happens from front in queue so the front elementthat we pushed in q1 will get popped from q2 
        }// and thisprocess wll cpntinue until q2 is empty.
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    cout<< "t="<<st.top()<<endl;
    cout<<"s="<<st.size();
    return 0;
}