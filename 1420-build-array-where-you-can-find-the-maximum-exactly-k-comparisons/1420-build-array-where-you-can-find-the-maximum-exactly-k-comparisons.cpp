class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        if(k == 0)
            return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(m+1, -1)));
        return arrays(n, m, k, 0, 0, dp);
    }

    int arrays(int n, int m, int k, int max, int ind, vector<vector<vector<int>>>& dp){
        if(ind == n){
            if(k == 0)
                return 1;
            else return 0;
        }
        if(dp[ind][k][max] != -1) 
            return dp[ind][k][max];
        if(k == 0 && ind < n){
            long long ret = 1;
            for(int i = 1 ; i <= n-ind ; i++)
            {
                ret = (ret*max)%1000000007;
            }
            return ret;
        }


        long long ans = 0;
        for(int i = 1 ; i <= m ; i++){
            if(i > max){
                ans = (ans + arrays(n, m, k-1, i, ind+1, dp));
            }else{
                ans = (ans + arrays(n, m, k, max, ind+1, dp));
            }
        }

        return dp[ind][k][max] = ans%1000000007;
        
    }
};