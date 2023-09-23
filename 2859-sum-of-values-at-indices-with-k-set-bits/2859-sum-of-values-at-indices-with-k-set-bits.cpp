class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        
    auto count = [&] (int num) {
        int count = 0;
        while (num > 0) {
            if (num & 1) {
                count++;
            }
        
            num >>= 1;
        }
    
        return count;
    };
        int sum=0;
        for(int i = 0; i < nums.size(); i++){
            if(count(i)==k)
                sum+=nums[i];
            cout<<sum<<" ";
        }
        return sum;
    }
};