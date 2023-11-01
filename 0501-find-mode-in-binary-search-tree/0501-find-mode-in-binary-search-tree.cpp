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
    unordered_map<int, int>umap;
    
    int height(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        else {
            
            // Compute the height of each subtree
            int lheight = height(node->left);
            int rheight = height(node->right);
    
            // Use the larger one
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    // Function to print level order traversal a tree
    void printLevelOrder(TreeNode* root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
            printCurrentLevel(root, i);
    }
    
    // Print nodes at a current level
    void printCurrentLevel(TreeNode* root, int level)
    {
        if (root == NULL)
            return;

        if (level == 1)
            {
                umap[root->val]++;
            }

        else if (level > 1) {
            printCurrentLevel(root->left, level - 1);
            printCurrentLevel(root->right, level - 1);
        }
    }

    vector<int> findMode(TreeNode* root) {
        printLevelOrder(root);
        
        int freq = INT_MIN;
        
        vector<int>nodes;
        
        if(root == NULL)
            return nodes;

        for(auto val:umap)
        {
            if(freq <= val.second)
            {
                freq = val.second;
            }
        }

        for(auto val:umap)
        {
            if(val.second == freq)
            {
                nodes.push_back(val.first);
            }
        }

        return nodes; 
    }
};