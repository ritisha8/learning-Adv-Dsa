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
     stack<Node*>st1;
     stack<Node*>st2;
     st1.push(root);
     while(!st1.empty()){
        Node* temp=st1.top();
        st1.pop();
        st2.push(temp);
           if(temp->left!=NULL){
            st1.push(temp->left);
          }
          if(temp->right!=NULL){
            st1.push(temp->right);
          } 
     }
     while(!st2.empty()){
        Node * temp=st2.top();
        ans.push_back(temp->data);
        st2.pop();
     }
     return ans;
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