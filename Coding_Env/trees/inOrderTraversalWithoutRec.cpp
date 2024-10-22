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

vector<int> inOrder(Node *root){
    vector<int>ans;  // this will store in order
    if(root==NULL) return ans;
    stack<Node*>st;  // this will be used to store the left side like suxilary stack spaec in recrusion stores all previous left root
    while(true){
        if(root!=NULL){  // if root!= null 
            st.push(root);  //we will push root instack
            root=root->left;  //then we move to left , likein recursion we move to left until ,left is null, then we backtrack and print the topmost ellemnt in aux stack
        }
        else{
            if(st.empty()==true) break;
            root=st.top();  // when root becomes null ,we make the topmost ellemtn of stack as root, like we do in recursion , when left becomes null we bacltrack and print the root , and then check for right
            st.pop();  // now we pop this node out of stack 
            ans.push_back(root->data);  // and then we store it in vector,the topmost ellemtn in stack, or we can say leftmost in tree
            root=root->right;   // then we printed the root, now wemove to root->right, as this is inorder we move to right, left->root->right
        }
    }
    return ans;
}
int main(){
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    vector<int>v=inOrder(root);
    for(auto it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}