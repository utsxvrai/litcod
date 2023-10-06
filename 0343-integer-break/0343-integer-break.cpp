class Solution {
public:

vector<int> dp;

int rec(int n,int cnt)
{
    if(n==0) {
        if(cnt>=2)
        return 1;
        
        return 0;
    }
    
    if(dp[n]!=-1)
        return dp[n];
    
    int ans=1;
    
    for(int i=1;i<=n;i++)
        ans= max(ans,i*rec(n-i,cnt+1));
    
    return dp[n]= ans;
}

int integerBreak(int n) {
    dp.resize(n+1,-1);
    return rec(n,0);
}
};