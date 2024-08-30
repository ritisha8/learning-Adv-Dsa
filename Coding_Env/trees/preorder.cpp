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
void preOrder(TreeNode *root){  // this will give us preorder of the whole tree
    if(root==NULL) return;
    cout<<root->data<<" ";  // induction step first printin root because it is preorder-> root left right
    preOrder(root->left);  // this will give us preorder of left side of tree as we are passing root->left as root now
    preOrder(root->right); // this will giev us preorder of right side of tree as we are passing root->right as root now

}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    preOrder(root);
    
}