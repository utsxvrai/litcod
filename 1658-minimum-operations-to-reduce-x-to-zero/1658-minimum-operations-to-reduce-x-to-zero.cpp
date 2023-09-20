class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        if (target == 0) return nums.size();
        
        int maxLen = 0, currSum = 0, left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];
            
            while (currSum > target && left <= right) {
                currSum -= nums[left++];
            }
            
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        
        return maxLen > 0 ? nums.size() - maxLen : -1;
    }
};