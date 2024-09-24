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
TreeNode* invertTree(TreeNode* root){
    //fisrt we will check for ede cases , what could be the edge cases , the root node could beNULL or root right and left node isd nuLL, means there is only one node
    //when there is only one  node or root node is nuLl we simply return NULL;
    if(root==NULL || root->left==NULL && root->right==NULL){
        return root;   // if only root is there or no root is there then we return root becayse in case of only root the invert will bbe root only
    }
    if(root->left==NULL){  // if root left is nuLL but root right has its left right thn we make root  left = invert of root right, as prev root left was null
    // now root right will be null but before that we need to invert the root right and put it in root left
        root->left=invertTree(root->right);
        root->right=NULL;
    }else if(root->right==NULL){
        root->right=invertTree(root->left);
        root->left=NULL;
    }else{
     // if both left and right are there then we make  variable temp to store the left part of root 
     TreeNode* temp=root->left; //  we store te whle left paert of tree in temp 
     root->left=invertTree(root->right);// then we put the invert of right part in left as we know invertTree function returns the inverted tree with root as same
     root->right=invertTree(temp);  // now ourn left subtree has the right subtree inverted in it and now we need right subtree to have the left subtree as well so we will just put the inverted version of temp in root right, as we previously store root left in temp;
    }
    //now our tree is correctly inverted;
    return root;
}
int main(){
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    invertTree(root);
    return 0;
}
