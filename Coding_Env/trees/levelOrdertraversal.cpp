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
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>>ans;  /// this will store level wise tree nodes values
    queue<TreeNode*>q;    // this willl store nodes
    if(root==NULL) return ans; // edge case
    q.push(root);
    while(!q.empty()){
        vector<int>level;// store all elemnets levelwise like for first level whenthere is only one ellemnt it willstore onlyon eellemnt,  and then agagain if queue isnot empty due to ,eft and right nodes of temp, 
        //then aggain new level is created for storing the 2nd level elements , otherwise if we use same level and declare it with vector<vector> and queue , it will store level wise but also store temps of prev levels
        int n=q.size(); // storing the size of queue so that elevelwise nodes should be stored, as we know at level one when thereis only root then lemnt is onkyone so we will run alooptill n only tillon eonly andafter that again
        // level vector will be created and againq size willl be stored in n ,and now size will be 2 so now hile loop will run till 2 onyl
        while(n--){
             TreeNode* temp=q.front(); //ectracting the first node and stroing it in temp
             q.pop();   // 
             level.push_back(temp->data);
             if(temp->left!=NULL){
             q.push(temp->left);
             }
             if(temp->right!=NULL){
            q.push(temp->right);
            }
            
        }
       ans.push_back(level);
    }
    return ans;


}
int main(){
  TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(8);
    root->right = new TreeNode(30);
    root->right->left = new TreeNode(40);
    root->right->right = new TreeNode(50);
    vector<vector<int>>v = levelOrder(root);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            cout << v[i][j] << " ";
        }
        cout << endl; // New line after each level
    }
    return 0;
}