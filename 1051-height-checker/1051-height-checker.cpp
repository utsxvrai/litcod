class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> gg;
        for(auto x : heights) gg.push_back(x);
        sort(heights.begin(), heights.end());
        int c=0;
        for(int i  = 0 ; i < heights.size() ; i++){
            if(gg[i] != heights[i]) c++;
        }
        return c;
        
    }
};