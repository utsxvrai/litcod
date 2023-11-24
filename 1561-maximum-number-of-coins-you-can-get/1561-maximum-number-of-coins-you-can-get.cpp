class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int ans = 0,  k = piles.size();
        sort(piles.begin(), piles.end());
        for(int i = k - 2; i >= k / 3; i -= 2)
            ans += piles[i];
        
        return ans;
    }
};