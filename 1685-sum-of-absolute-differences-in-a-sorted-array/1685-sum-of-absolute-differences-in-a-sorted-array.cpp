class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
      int n= nums.size();
        int sum=0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
        }

        vector<int> diu(n);
        int startSum =0;
        for (int i=0; i<n; i++) {
            if (i>0) startSum += nums[i-1];
            sum -= nums[i];
            diu [i] = abs(startSum - nums[i]*i) + abs(sum - nums[i]*(n-i-1));
        }

        return diu;
    }
};