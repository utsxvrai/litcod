class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int cnt(0);
        vector<int> res;
        sort(nums.begin() , nums.end());
        res.push_back(nums[0]);
        for(int i = 1; i < nums.size() ; i++){
            if(nums[i] <= res[i-1] || nums[i] == nums[i-1] ){
                res.push_back(res[i-1]+1);
                cnt += (res[i] - nums[i]) ;
            }
            else{
                res.push_back(nums[i]);
            }
        }
        // for(auto x : res) cout<<x<<" ";
        return cnt;
        
    }
};