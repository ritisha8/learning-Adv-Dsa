#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *right,*left;
    Node(int x){
        data=x;
        right=left=NULL;
    }
};
vector<int> postOrder(Node* root){
    vector<int>ans;
    if(root==NULL) return ans;
    Node * curr=root;
    stack<int>st;
    while(curr!=NULL){
        st.push(curr);
        curr=curr->left;
    }
    while(curr==NULL){
        Node *temp=st.top()->right;
        if(temp==NULL){
            ans.push_back(st.top());
        }
        if(temp!=NULL){
            curr=temp;
        }
    }
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    vector<int>v=postOrder(root);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}