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

    long long getsum(TreeNode* root , vector<long long>& sums){
        if(root==NULL) return 0;
        long long sum = root->val + getsum(root->left,sums) + getsum(root->right,sums);
        sums.push_back(sum);

        return sum;
    }
    

    int maxProduct(TreeNode* root) {
        vector<long long> sums;
        long long total = getsum(root, sums);
        long long maxx=0;

        for(auto i : sums){
            long long res = i * (total - i);
            if(res > maxx){
                maxx=res;
            }
        }
        return maxx % 1000000007;
    }
};