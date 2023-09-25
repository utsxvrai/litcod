class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums.size(),0);
        for(int i = 0 ; i < nums.size() ;i++){
            for(int j = 0 ; j < nums.size() ;j++){
                if(nums[i]>nums[j] && j!=i){
                    v[i]++;
                }
            }
        }
        return v;
    }
};