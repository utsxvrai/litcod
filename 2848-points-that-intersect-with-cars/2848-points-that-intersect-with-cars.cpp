class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> co;
        for(int i = 0 ; i < nums.size() ; i++){
            int a = nums[i][0];
            int b = nums[i][1];
            for(int  i = a ; i <=b ; i++){
                co.insert(i);
            }
        }
        return co.size();
        
        
    }
};