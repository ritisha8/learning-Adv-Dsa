#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
    node *prev;
    node(int x){
        data=x;
        next=prev=NULL;
    }
};
node *insertBeg(node *head, int x){  //insertion at beg 
    node *temp=new node(x);     // memory allocating to temp node  and making its next and prev to null
    if(head==NULL){            // chking edge case if head equals to null
        return temp;           // if yes , we return temp to head in main funtion
                       // now if there are no nodes head will be  linked to the temp; and one node is added;
    }
    else{     // if head is not null , control comes here
        temp->next=head;   // temp->next will point ot head as head is first node as we it is insert at beg , its next shoudl point to the first node
        head->prev=temp;    // and first node's prev should point to temp; (as it doubly list)
        return temp;       // then return temp to head in the main function and now head willl point to this temp , as it should as it is insertion at beg
    }
}
node *insertEnd(node *head,int x){   // insertiona at end
    node *temp=new node(x);      // memory allocating to temp node  and making its next and prev to null
    node *r=head;                // in order to insert at end we need to have a pointer to last node, so we make a pointer pointing to head and insert
    //then we will iterate it till the node next is null , so that we find last node, as last node's next is obviously going to be null
    if(head==NULL){    // chking for edge cases , if head== null, 
        return temp;    // return temp to head in main function as there is no node so head will point to this temp
    }      // if there are nodes then control comes here
    while(r->next!=NULL){    // this will iterate till r nxt is not null , when it finds null , it will come ou tof loop amd we will have r pointing to last node
        r=r->next;           
    }
    temp->prev=r;   // now we temp next is larready null temp prev should point to r so this is it
    r->next=temp;   // now r->nextshoudl point to temp , hence link is established in doubly list
    return head;   // now return sam head to main function as it i inserrtion at end head will not change
    
}
node *delBeg(node *head){  // del at beg
    node *r=head;        // for del at beg we take a pointer pointing to head
     if(head==NULL){    // chking for edge cases if head is null, return head that is null to the main function because no deletion can happen then
        return head;
     }
     else{      // if head is not null, control comes here
        head=r->next;    // npw head should point tp the node next to 1st node as first node needs to be deleted, so here we do head=r->next, as r is the head pointing to first node
        delete(r);    // now delte r and hence first node is deleted
        return head;    //return the modified head to the main function, as it is del at beg head is changed
     }
}
node *delEnd(node *head){  // deletion at end
    node *r=head;          // now for del at end , we need a pointer poiting to the last node and last secomd node
    node *r2=head->next;    // so we take 2 pointers, one pointing to head and next pointing to node next to head
    if(head==NULL){         // chking for edge cases if head is null, return head that is null to the main function because no deletion can happen then
        return head;        
    }  // now control comes here uif head is not null means nodes are there

    while(r2->next!=NULL){   // this will run till r2 reaches last node, that is r2 's next is null
        r=r2;                 // it will assign r2 to r
        r2=r2->next;          // and r2->next node will be assiigned to r2
    }     //now after coming out o loop we have r2 last node and r as last node
    r->next=NULL;    // now in order to delt last node we do r->next null because r ill become last node now , and r2 will be deleted
    delete(r2);      // now r2 will be deleted, hence last node is deleted
    return head;     // return same head to main function as it is del at end , it willl make no chnge tp head

}
void display(node *head){     // display fucntion
    if(head!=NULL){        // if head is null , control comes here, otherwise it will return to the main fucntion and will not diplay anything as there i no node
        cout<<head->data<<" ";   // it will print head node's data part 
        display(head->next);     // and then display function will run recursively with head->next as paramenter , now same function will run for node next to head
        // and data will be printed, and whenever it becomes null , it willl simply return;
    }
    return;
}

int main(){
    node * head=NULL;
    head=insertBeg(head,40);
    head=insertBeg(head,50);
    head=insertBeg(head,60);
    head=insertEnd(head,70);
    head=insertEnd(head,80);
    head=delBeg(head);
    head=delEnd(head);

    display(head);
    return 0;
}