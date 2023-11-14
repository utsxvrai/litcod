class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>kiki;
        for(char i:s)kiki.insert(i);
        int isu = 0;
        for (char c:kiki) {
            auto i = s.find(c);
            auto j = s.rfind(c);
            if (i != -1 && j != -1 && i < j) {
                unordered_set<char> u(s.begin() + i + 1, s.begin() + j);
                isu += u.size();
            }
        }
        return isu;
    }
};