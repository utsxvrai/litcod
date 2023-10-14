class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& cost,vector<int>&time,int i,int remain){
        if(remain <= 0)
            return 0;
        if(i == time.size())
            return 1e9;
        if(dp[i][remain] != -1)
            return dp[i][remain];
        int take = cost[i] + solve(cost,time,i+1,remain - time[i] - 1);
        int notTake = solve(cost,time,i+1,remain);
        return dp[i][remain] = min(take,notTake);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        dp = vector(time.size(),vector(time.size()+1,-1));
        return solve(cost,time,0,time.size()); 
    }
};