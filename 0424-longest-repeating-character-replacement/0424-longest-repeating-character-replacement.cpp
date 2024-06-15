class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26);
        int l(0), r(0), res(0), maxCount(0);
        while(r<s.size()){
            count[s[r] - 'A']++;
            maxCount = max(maxCount, count[s[r] - 'A']);
            if (r - l + 1 - maxCount > k) {
                count[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
            r++;
        }
        return res;
        
    }
};