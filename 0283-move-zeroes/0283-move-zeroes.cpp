class Solution {
public:
            int j= 0;

    void moveZeroes(vector<int>& nums) {
        for(int i = 0 ; i < nums.size(); i++)
        {
            if(nums[i] != 0){
                swap(nums[i],nums[j++]);
            }
        }
        
    }
};