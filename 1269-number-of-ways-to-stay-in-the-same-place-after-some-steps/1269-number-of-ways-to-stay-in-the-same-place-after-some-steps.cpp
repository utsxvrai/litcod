class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int MOD = 1000000007;
        
    int DFS(int steps, int index)
    {
        if(index < 0 || index >= n || steps < index)
            return 0;

        if(steps == 0)
            return index == 0;

        if(dp[steps][index] != -1)
            return dp[steps][index];

        long long ret = 0LL + DFS(steps - 1, index) + DFS(steps - 1, index - 1) + DFS(steps - 1, index + 1);
        
        return dp[steps][index] = ret % MOD;
    }

public:
    int numWays(int steps, int arrLen) {
        
        n = arrLen;
        dp = vector<vector<int>>(steps + 1, vector<int>(min(steps / 2 + 1, n), -1));
        return DFS(steps, 0);
    }
};