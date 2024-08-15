#include<bits/stdc++.h>
using namespace std;
struct Queue{
    int cap, size, front;
    int *arr;
    Queue(int x){
        cap=x;
        size=0;
        front=0;
        arr=new int[cap];
    }
bool isEmpty(){
    return (size==0);
}
bool isFull(){
    return (size==cap);
}
int getfront(){
    if(isEmpty()) return -1;
    else return front;
}
int getRear(){
    if(isEmpty()) return -1;
    else{
       return ((front+size-1)%cap);
    }
}
void enqueue(int x){
    if(isFull()) return;
    else{
        int rear=getRear();  //we will get rear from this but that will not bevalid for circular queue so we do 
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
}};
int main(){
    Queue q(5);
    q.enqueue(10);  
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.dequeue();
    q.enqueue(60);
    q.enqueue(70);
    cout<<"front:"<<q.getfront()<< endl;
    cout<<"rear:"<<q.getRear()<< endl;
}