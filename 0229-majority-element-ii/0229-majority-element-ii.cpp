class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> answer;
        unordered_map<int,int> num_count;
        for(int i = 0;i<nums.size();i++){
          if(num_count.find(nums[i])!=num_count.end()){
            num_count[nums[i]]++;
          }else{
            num_count[nums[i]] = 1;
          }
        
        }
        
        for(const auto  &pair : num_count){
          if(pair.second > nums.size()/3){
            answer.push_back(pair.first);
          }
        }
        return answer;
    }
};