class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;
        int prev = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i] <= prev){
                prev = nums[i];
                continue;
            }

            int ops = ceil((double)nums[i]/(double)prev);
            result+=(ops-1);
            prev = nums[i]/ops;
            
        }  
        return result; 
    }
};