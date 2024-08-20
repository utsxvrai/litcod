/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int maxh(TreeNode* root,int &Maxd){
        if(root==NULL) return 0; 
        int lh = maxh(root->left,Maxd) ;
        int rh = maxh(root->right,Maxd);
        Maxd=max(lh+rh,Maxd);
        
        return 1+ max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int Maxd=0;
        maxh(root,Maxd);
        return Maxd;
        
    }
};