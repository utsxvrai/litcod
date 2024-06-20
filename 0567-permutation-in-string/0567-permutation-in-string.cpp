class Solution {
private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp1(26,0);
        int mt=0;
        int n = s1.size() , m = s2.size();
        if(n>m) return false;
        for(int i = 0 ; i < n ; i++){
            mp1[s1[i] - 'a']++;
            mp1[s2[i] - 'a']--;
        }
        if(isPermutation(mp1)){
            return true;
        }
        for (int i = n; i < m; i++) {
            mp1[s2[i] - 'a']--;
            mp1[s2[i - n] - 'a']++;
            if (isPermutation(mp1)) {
                return true;
            }
        }
        return false;
    }
};