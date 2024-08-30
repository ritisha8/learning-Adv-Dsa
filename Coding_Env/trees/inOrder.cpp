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
void inOrder(TreeNode *root){  // this will give us postorder of the whole tree
    if(root==NULL) return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    inOrder(root);
    
}