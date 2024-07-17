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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
        root = helper(root, del_set, forest);
        if (root != nullptr) {
            forest.push_back(root);
        }
        
        return forest;
    }

     TreeNode* helper(TreeNode* node, unordered_set<int>& del_set, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        
        node->left = helper(node->left, del_set, forest);
        node->right = helper(node->right, del_set, forest);
        
        if (del_set.find(node->val) != del_set.end()) {
            if (node->left) forest.push_back(node->left);
            if (node->right) forest.push_back(node->right);
            delete node;
            return nullptr;
        }
        
        return node; 
    }
};