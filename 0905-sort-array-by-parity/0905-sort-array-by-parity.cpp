class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        
        vector<int> vi(n,0);
        int j=0,k=n-1;
        for(int i = 0 ; i < n; i++){
            if(nums[i]%2==0){
                vi[j]=nums[i];
                j++;
            } 
            else{
                vi[k]=nums[i]; 
                k--;
            }  
        }
        return vi;
        
    }
};