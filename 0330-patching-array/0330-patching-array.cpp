class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long res = 0;
        long long ub = 1, i = 0;
        while (ub <= n)
        {
            if (i < nums.size() && nums[i] <= ub)
            {
                ub += nums[i++];
            }
            else
            {
                ub += ub;
                res++;
            }
        }
        return res;
    }
};