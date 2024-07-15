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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,pair<int,int>>m;
        unordered_map<int,int>isChild;
        for(int i=0;i<d.size();i++)
        {
            int parent=d[i][0],child=d[i][1],isLeft=d[i][2];
            if(isLeft==1)
            {
                m[parent].first=child;
            }
            if(isLeft==0)
            {
                m[parent].second=child;
            }
            isChild[child]=1;
        }

        int rootNode=-1;
        for(int i=0 ; i<d.size();i++)
        {
            if(isChild[d[i][0]]==0)
            {
                rootNode=d[i][0];
            }
        }
        TreeNode* root=new TreeNode(rootNode);
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            TreeNode* node=q.front();
            q.pop();
            TreeNode* left,right;
            if(m[node->val].first)
            {
                node->left=new TreeNode(m[node->val].first);
                q.push(node->left);
            }
            if(m[node->val].second)
            {
                node->right=new TreeNode(m[node->val].second);
                q.push(node->right);
            }
        }
        return root;
    }
};