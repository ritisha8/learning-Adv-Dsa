#include<bits/stdc++.h>  
using namespace std;
struct node{   
    int data;
    node *next;
    node(int x){
        data=x;
        next=NULL;
    }
};
node *insertBeg(node *head, int x){   //insertion at beginning
    node *temp=new node(x);   // allocate memory to temp node with x as its data part and nex as null
    if(head==NULL){    // check for edge cases if head== NULL
       return temp;   // we return this temp node to head in main function , now head is pointing to temp
    }
    else{
        temp->next=head;  // if(not nULL) then temp->next will point to the first node which is head , so we do temp->next=head
        return temp;  //then return temp to head in main function, and now head is chnaged 
    }
}
node *insertEnd(node *head, int x){     //insertion at end
      node *temp=new node(x);  //first we will declare  a node temp and allocate memory to it using new keyword with the constructor node, 
      //now temp is stores with x in its data part and its next as null
      //now will check for the edge cases, 
      if(head==NULL){   //1st one being if head is null  as linked list is empty this will be first node
        return temp;   //if head is nULL , simply return temp to the main in which temp variable will be assigned to head.
      }
      else{          //if list is not empty
         //now we need to know the which is the last node in order to insert a node after that, so we will declare a pointer that will traverse through until it reaches last node ,
         node *r=head;
        while(r->next!=NULL){   // we know last node's next pointer will be null, this loop willr un till r->next is null that sitill last node
         r=r->next; // we will shft the r pointer to the next node node to which it is pointing
      }
      // now we when r->next==NULL has becom true ,that is r is the  last node
      r->next=temp;  // now we will assign the next pointer of r to point to temp and we know temp next is allready null throygh the constructor
      return head;  //then return head to main
}
}
node *insertPos(node *head,int pos,int x){   //insertion at a certain position
    node *temp=new node(x);  //allocating mwmory to node temp and and now temp is creatd with x in data part and next as null
    //first we will check for edge cases
    // if head == null will not work here directly because eve if head is null , psition could be 1 then insetions possible right?, so first we need to see if pos==1
    if(pos==1){
        temp->next=head;  //if pos=1, temp->next should point to the first ellemnt or if the linkedlsit is empty then null , so we do temp->next=head as head will point to the 1st ellemnt and null when list is empty
        return temp;  //then return temp to head in main untion
    }
    node *r=head; // now we ill make a pointer that will point to th position jsut before the position of the node we wanrt to insert 
    //so now we will traverse traverse throyggh the linked list to find the node just before the position we want to insert the node at
    for(int i=1;i<=pos-2 && r!=NULL;i++)  // now we run a loop from i = 1 to pos -2 because i pos= 4 it will run till 2, we willl understand further hy we are doing this, 
    {                             //and we check r!=NULL so when we ra egiven a pos that is after the last eelemnt , r becomes null there because last ellemnt is crossed and hence we will handle this edge case after this loop
        r=r->next;     // we will move the r pointer to next node till pos-2 because when i =1, r will pointot the next position, whn i =2, r will point to the 3rd position, so if we are given pos=4 we need 3rd pos node in order 
    }         //to insert node just after it, so we found the 3rd pos node in just 2 iterations right?, so we  run the loop till pos-2
    //now handling the edge case if r becomes null, that is when a pos is given after the list is finished
    if(r==NULL){
        return head; // if r becomes null after the for loop ad pos is not found we il simpty return head vaue back to head in main function
    }
    temp->next=r->next;  //temp->next will point to node next to r because that should now be next to temp, while inserting at given pos
    r->next=temp;   // now r->next will point ot temp that means r-next which was pointing to it prev next node willl start pointing to temp now and that link will be broken
    // node is inserted
    return head; // now return head to main function
}
node *delBeg(node *head){// deletion at beginning
    if(head== NULL){    // check for edge cases 
        return head;    // if head is nuLL return head to head in main fuction
    }
    node *r=head;  // now  we will create  a pointer pointing to the head node for del at beg
    head=r->next;  // now head will point to r->next that is node next to first node
    delete(r);     // and then we will delete r that is first node
    return head;

}
node *delEnd(node *head){   // deletion at end
//in order to do del at end we should know the last and llast second node and
    node *r=head;
    node *r2=head->next;  // so we make pointers pointing to r =first and  r2= second node
    if(head==NULL){     // chking for edge case , if head is null we will return null
        return head;
    }

    while(r2->next!=NULL){ // this loop will run till r2->next =NULL, that is till r2 becomes the last node 
        r=r2;
        r2=r2->next;    //to find the last and last second node we asssign r2 to r and r2->next to r2 until we reach the last node
    }     // now when we come out of this loop we have r pointing to last second node and r2 pointing to last node
    r->next=NULL;  // here we make r->next = NULL to  break its link with r2 and make it last node
    delete(r2);    // and then delete r2
    return head;
}
node *delPos(node *head, int pos){     // del at a certain pos
// we will chk fro edge cases like if pos==1
 node *r=head;   // we will make  a pointer pointing ot head node
 node *r2=head->next;  
    if(pos==1){  // if pos== 1 , then same del at beginning logic
        head=r->next;
        delete(r);
        return head;
    } // now we will find the node just before position and the node jsut at the position
    for(int i=1;i<pos-1 && r2!=NULL;i++){   //  assume pos=4 ,we will run a loop till i < pos-1 because,
    // when i=1 ,r is at 2nd pos, and r2 is at 3rd, and when i=2 r is at pos 3 and r2 is at pos 4 , hence we got r in second last and r2 at t the exact position in just 2 steps ,so we run it till <pos-1 or <=pos-2
        r=r2;
        r2=r2->next;
    } // now we have found the last second node to the pos required. the the node to the pos reg as well
   // first handle the dge case of we got a pos more than we nodes in list, r2 will become null after getting out of fo loop
    if(r2==NULL){
        return head; // we make no change and simply return head 
    }
    r->next=r2->next;   // now here r next will point to the node next to r2 
    delete(r2);    // and we delete r2 which is at exact position , hence node deleted at position
    return head;  // then just return head like usual

}
void display(node *head){   // this is a simple display function 
    node *r=head;       // here we take a pointer r that is pointin to head, we can do it with head as well but jsut out of habit
    while(r!=NULL){    // this loop will run if head is not nULL
        cout<<r->data<<" ";  // r->data , that is head node data will be printed
        r=r->next;   // then r will point ot the next node until r becomes  NULL
    }
}
int main(){
   node *head=NULL;
   // we are returning head evrytime in order to pass the same ehead in every nnect execution of funtion, head only changes in case of insertion at beg , othrwise it stay same
   head=insertBeg(head,10);
   head=insertBeg(head,5);
   head=insertBeg(head,3);
   head=insertEnd(head,20);
   head=insertEnd(head,30);
   head=insertEnd(head,40);
   head=insertPos(head,4,15);
   head=delBeg(head);
   head=delEnd(head);
   head=delPos(head,5);
   display(head);
   return 0;
}