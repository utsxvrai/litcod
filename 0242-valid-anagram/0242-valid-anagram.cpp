class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> vs(26,0);
        vector<int> vt(26,0);
        for(auto x : s){
            vs[x-'a']++;
        }
        for(auto x : t){
            vt[x-'a']++;
        }
        return vs == vt;
        
        
    }
};