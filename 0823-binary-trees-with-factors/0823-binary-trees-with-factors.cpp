class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int mod = 1e9 + 7;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> dp(n, 1);
        int sum = 1;
        for(int i = 1; i < n; ++i) {
            int p1 = 0, p2 = i - 1;
            while(p1 <= p2) {
                long long mul = 1LL * arr[p1] * arr[p2];
                if(mul > arr[i]) --p2;
                else if(mul < arr[i]) ++p1;
                else {
                    dp[i] = (dp[i] + (((p1 != p2 ? 2LL : 1LL) * dp[p1]) % mod * dp[p2]) % mod) % mod;
                    --p2, ++p1;
                }
            }
            sum = (sum + dp[i]) % mod;
        }
        return sum;
    }
};