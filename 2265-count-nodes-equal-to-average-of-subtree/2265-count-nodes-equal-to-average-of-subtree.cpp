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
    pair<int,int>helper(TreeNode *root, int &cnt)
    {
        if(root == NULL)
            return {0,0};
        auto it1 = helper(root->left,cnt);
        auto it2 = helper(root->right,cnt);
        int sum = root->val + it1.first + it2.first;
        int n = 1 + it1.second + it2.second;
        if(sum/n == root->val)
            cnt++;
        return {sum,n};
    }

    int averageOfSubtree(TreeNode* root) {
        int cnt {};
        helper(root,cnt);
        return cnt;
    }
};