class Solution {
public:
    vector<vector<int>> adj;  
    int maxLength;

    int dfs(int node, vector<int>& parent, string& s) {
        int max1 = 0, max2 = 0; 

        for (int child : adj[node]) {
            if (child == parent[node]) continue; 

            int childLen = dfs(child, parent, s);

            if (s[child] != s[node]) {
                if (childLen > max1) {
                    max2 = max1;
                    max1 = childLen;
                } else if (childLen > max2) {
                    max2 = childLen;
                }
            }
        }
        maxLength = max(maxLength, max1 + max2 + 1);
        return max1 + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        maxLength = 0;

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
            adj[i].push_back(parent[i]);
        }
        dfs(0, parent, s);

        return maxLength; 
    }
};