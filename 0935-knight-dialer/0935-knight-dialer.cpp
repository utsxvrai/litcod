class Solution {
public:
    int mod=(1e9+7);
    vector<vector<int>>moves;
    vector<vector<vector<int>>>dp;
    int func(int n,int i,int j,vector<vector<int>>&grid)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0 || grid[i][j]==-1)
        {
            return 0;
        }
        if(n==0)return 1;
        if(dp[n][i][j]!=-1)return dp[n][i][j];

        long long a=0;
        for(int k=0;k<moves.size();k++)
        {
            a=(a+func(n-1,i+moves[k][0],j+moves[k][1],grid))%mod;
        }
        return dp[n][i][j]=a%mod;
    }

    int knightDialer(int n) {
        long long ans=0;
        dp.resize(n+1,vector<vector<int>>(11,vector<int>(11,-1)));
        moves={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2}};
        vector<vector<int>>grid={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                ans+=func(n-1,i,j,grid)%mod;
            }
        }

        return ans%mod;
    }
};