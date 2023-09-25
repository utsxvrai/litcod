class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        auto sum = [&] (vector<int> arr){
          int s=0;
            for(auto i : arr){
                s+=i;
            }
            return s;
        };
        int siu=INT_MIN;
        for(auto i : accounts){
            int m = sum(i);
            siu=max(siu,m);
        }
        return siu;
    }
};