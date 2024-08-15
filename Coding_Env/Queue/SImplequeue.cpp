// simple implementation of queue which does all operations in 0(1) except deque because in deque we have to runa loop to move the array ellemnet just after 1st ellemnt to 1 position back
// so that takes 0(n) where n is size of queue
#include<bits/stdc++.h>
using namespace std;
struct Queue{  // created a queue structure
    int size, cap;   // variables taken size and capacity
    int *arr;       // and arr pointer
    Queue(int x){ // defined a constructor with parametre as x whcih defines capacity of queue
     cap=x;  // here we assigned the x to cap
     size=0;  // and initialized size =0;
     arr= new int[cap];   // created an array of cap size
    }

bool isEmpty(){   //  fucntion to check if queue is empty
    return (size==0);   // if size==0 it will return true othewise false
}
bool isFULL(){   // function to check if queue is full
    return (size==cap);  // if size== capacity , it will returnr true otherwise false;
}
int getFront(){   // fcntion to get front we did the returntype as int in order for this function to return an integer
    if(isEmpty()) return -1;  // returns -1 if queue is empty 
    else return 0;        // if not return 0 as front will always be 0 in simple implemenation
}
int getRear(){   // function to return rear
  if(isEmpty()) return -1;   //return -1 if queue is empty
  else return size-1;  // otherwise return size-1 as last element will always be size-1 in simple implememtation ,
  // as we are jsut moving the aray backward by one poition as we delete one element, so the size will be the size of array and we know aray starts from 0 so here we do size-1 in orderr to get the last ellemnt
}
void enQueue(int x){  // enqueue fucntion inserts elelmnt 
if(isFULL()) return;  //if queue is full we will return, because if queue is full no further insettion can be done
else{
    arr[size]=x; // if queue is not full , lets say it is empty size is 0 now we do arr[0]= x
    size++;  // now we make size++ and size becomes 1 now
} 
}
void deQueue(){   // now when we want to delete from queue
   if(isEmpty()) return;  // if queue is empty return void 
   else{                      // if not control comes here
    for(int i=0;i<size;i++){   // now a loop runs from 0 to size and 
        arr[i]=arr[i+1];  // moves all the llements one psoition backwards starting from the second element 
    } // first element is removed and we get front as another elemnt
    size--;  // now we do sizee-- as the loop by making all ellemts move one step backwards it reduced the size by 1 so w do size--
   }
}
};
int main(){
Queue q(5);    // now we define a q object of structure and defien a contructor with cap as 5

q.enQueue(10);   // calls enqueue fucntion and returns [10]  
q.enQueue(20);  // returns [10,20]
q.enQueue(30);   // returns [10,20,30]
q.enQueue(40);   // returns [10,20,30,40]
cout<<"front:"<<q.getFront()<<endl;   // now we get front from this statement
cout<<"rear:"<<q.getRear()<<endl;   // now we get rear from this statement
q.deQueue();   // now dequue will be called and returns front as 0 and rear as 2
q.deQueue();   // now dequue will be called and returns front as 0 and rear as 1
cout<<"front:"<<q.getFront()<<endl;   //front =0
cout<<"rear:"<<q.getRear()<<endl;     // rear =0

}
