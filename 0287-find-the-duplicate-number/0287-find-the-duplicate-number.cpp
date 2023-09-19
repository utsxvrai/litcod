class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int x=0;
        int n = nums.size();
        for(int i = 0 ; i < n-1 ; i++){
            if((nums[i]^nums[i+1])==0){
                
             x = nums[i];
                break;
            }
        }
        return x;
        
    }
};