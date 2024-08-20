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
    long long maxx=INT_MIN , total=0;

    long long getsum(TreeNode* root ){
        if(root==NULL) return 0;
        long long sum = root->val + getsum(root->left) + getsum(root->right);
        maxx = max(maxx, (total-sum)*sum);
        return sum;
    }
    

    int maxProduct(TreeNode* root) {
        total = getsum(root);
        getsum(root);

        return maxx % 1000000007;
    }
};