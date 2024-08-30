#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode *right,*left;
    TreeNode(int x){
        data=x;
        right=left=NULL;
    }
};
void postOrder(TreeNode *root){  // this will give us postorder of the whole tree
    //hypothetically this fucntion will return us the postorder traversal of whole tre post order means left righht root
    // so it will work same with samller input , so if we give it just the left part of tree it will wortk perfectly fine
    // and so with right part  , lets implement
    if(root==NULL) return;   // base condition least valid input when tree is empty we will simply return
    postOrder(root->left);   // this will give us postorder of left part
    postOrder(root->right);  // this will give us postorder of right part
    cout<<root->data<<" ";  // induction step to print the root data


}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    postOrder(root);
    
}