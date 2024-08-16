#include<bits/stdc++.h>
using namespace std;
struct Queue{
    int cap, size,front;
    int *arr;
    Queue(int x){
        cap=x;
        size=0;
        front=0;
        arr=new int[cap];
    }

    bool isEmpty(){
        return (size==0); // returns true if size ==0 , otherwise false
    }
    bool isFull(){
        return (size==cap);  // returns true if size== cap
    }
    int getFront(){
        if(isEmpty()) return -1;  // if no element is there return -1 so now front points to -1
        else return front;
    }
    int getRear(){
       if(isEmpty()) return -1;
       else return ((front+size-1)%cap);
    }
    void enqueue(int x){
        if(isFull()) return;
        else{
            int rear=getRear();
            rear=(rear+1)%cap;
            arr[rear]=x;
            size++;
        }
    }
    void dequeue(){
        if(isEmpty()) return;
        else{
            front=(front+1)%cap;
            size--;
        }
    }
};
int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    cout<<"f:"<<q.getFront()<<" "<<"r:"<<q.getRear()<<endl;
    q.enqueue(75);
    q.enqueue(80);
    cout<<"f:"<<q.getFront()<<" "<<"r:"<<q.getRear();
}