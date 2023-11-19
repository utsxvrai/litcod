class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int e=nums.size()-1,ans=0,val=nums[0],size=e;
        while(nums[e] != val){
            int ele=nums[e];
            while(ele == nums[e])    e--;
            ans += size-e;
        }
        return ans;
    }
};