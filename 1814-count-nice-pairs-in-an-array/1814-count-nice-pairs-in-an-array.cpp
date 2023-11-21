class Solution {
public:
    int MOD = 1e9 + 7;

    int rev(int x) {
        int ret = 0;

        while (x > 0) {
            ret = ret * 10 + x % 10;
            x /= 10;
        }

        return ret;
    }

    int countNicePairs(vector<int>& nums) {
        int ret = 0;

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i] - rev(nums[i]);
            ret = (map[curr] + ret) % MOD;
            map[curr]++;
        }

        return ret;
    }
};