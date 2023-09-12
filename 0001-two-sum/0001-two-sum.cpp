class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int x(0), y(0);
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                if(i!=j && nums[i]+nums[j]==target){
                    x=i;
                    y=j;
                    break;
                }
            
        }
        }
        vector<int> ans={x,y};
        return ans;
        
    }
};