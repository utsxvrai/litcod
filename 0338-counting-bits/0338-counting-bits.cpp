class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> siu(n+1);
        for(int i = 0 ; i < n+1 ; i++){
            siu[i] = siu[i >> 1] + (i & 1);
        }
        return siu;
    }
};