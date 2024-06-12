class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int p(1) , q(1);
        int zeroes = 0;
        for(auto x : nums){
            if(x != 0){
                p*=x;
            }
            else{
                zeroes++;
            }
        }
        for(int i = 0 ; i < nums.size() ; i++){
            if( (zeroes>=1) && nums[i] != 0){
                res.push_back(0);
            }
            else if((zeroes<1) && nums[i] != 0){
                res.push_back(p/(nums[i]));
            }
            
            else if( (zeroes == 1) && nums[i] == 0){
                res.push_back(p);
            }
            else{
                res.push_back(0);
            }
        }
        return res;
    }
};