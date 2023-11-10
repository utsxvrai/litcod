class Solution {
public:
    unordered_map<int, vector<int>> g;

    void dfs(int node, int prev, vector<int>& siu) {
        siu.push_back(node);
        for (int v : g[node]) {
            if (v != prev) {
                dfs(v, node, siu);
            }
        }
    }
    
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        for (auto x : adjacentPairs) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }   
        int root = 0;
        for (auto x : g) {
            if (x.second.size() == 1) {
                root = x.first;
                break;
            }
        }
        vector<int> siu;
        dfs(root, INT_MAX, siu);
        return siu;  
    }
};