class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0 , e= nums.size()-1;
        int mid=0 ;
        while(s<e){
            if(nums[s] > nums[e]){
                s++;
            }
            else{
                break;
            }
        }
        return nums[s];
        
    }
};