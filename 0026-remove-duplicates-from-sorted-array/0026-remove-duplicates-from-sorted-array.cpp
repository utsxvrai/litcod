class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int siu = 0;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]!=nums[siu]){
                siu++;
                nums[siu] = nums[i];
            }
        }
        return siu+1;
    }
};