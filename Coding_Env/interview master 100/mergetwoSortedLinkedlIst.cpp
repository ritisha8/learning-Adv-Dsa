// its brute force would be simply pushing all elemtns of both lists into a vector
// and then just sorting it through sort fucntion stl and then converting array to list using convert function The sort() function in
// STL typically takes time complexity of O(k log k), where k = n + m is the total number of elements. 
//sorting step complexity alone :O((n+m)log(n+m))
// total complexity would be O(n+m)+O((n+m)log(n+m))+O(n+m)=O((n+m)log(n+m))
//here the space complexity is O(1) whereas time complexity is O(n+m)
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
node* mergeTwoLists(node *head1,node *head2){
    node *dNode=new node(-1);
    node *temp=dNode;
    while(head1!=NULL && head2!=NULL){
        if(head1->data<=head2->data){
            temp->next=head1;
            temp=temp->next;
            head1=head1->next;
        }
        else{
            temp->next=head2;
            temp=temp->next;
            head2=head2->next;
        }
    }
    if(head1!=NULL) temp->next=head1;
    else temp->next=head2;

    return dNode->next;
}
void insertBeg(node *&head,int x){
    node *temp=new node(x);
    if(head==NULL){
        head=temp;
    }else{
     temp->next=head;
     head=temp;
    }
    
}
int main(){
    node *head1=NULL;
    node *head2=NULL;

    insertBeg(head1,40);
    insertBeg(head1,15);
    insertBeg(head1,10);
    insertBeg(head1,5);

    insertBeg(head2,20);
    insertBeg(head2,3);
    insertBeg(head2,2);

    node *head=NULL;
    head=mergeTwoLists(head1,head2);
    cout<<head->data;

return 0;

}