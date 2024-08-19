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
    int maxDepth(TreeNode* root) {
        int maxx = -1;
        stack<pair<TreeNode* , int>> st;
        st.push({root,0});
        while(st.size()>0){
            pair<TreeNode* , int> p = st.top();
            st.pop();
            TreeNode* temp = p.first;
            int d = p.second;
            if(temp == NULL){
                maxx = max(maxx, d);
                continue;
            }
            st.push({temp->left, d+1});
            st.push({temp->right, d+1});

        }
        return maxx;
        
    }
};