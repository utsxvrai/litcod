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
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;
        
        // Traverse each string in the input vector
        for (auto& s : strs) {
            string key = s;
            // Sort the string to form the key
            sort(key.begin(), key.end());
            // Add the original string to the vector for this key
            mp[key].push_back(s);
        }
        
        vector<vector<string>> res;
        
        // Collect all groups of anagrams from the map
        for (auto& kv : mp) {
            res.push_back(kv.second);
        }
        
        return res;
    }
};