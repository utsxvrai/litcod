class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int count[100001] = {0};
        int maxv = 0;
        for (int &n : nums){
            n += 50000; 
            if(maxv < n) maxv = n;
            ++count[n];
        } 
        
        int loc = 0;
        for (int i=0; i ^ 100001; ++i) {
            while(count[i] > 0) {
                --count[i];
                nums[loc++] = i - 50000;
            }            
        }
        
        return nums;
    
        
    }
};