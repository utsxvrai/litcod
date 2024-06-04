class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if (mp.find(c) != mp.end()) {
                mp[c]++;
            } else {
                mp[c] = 1;
            }
        }
        int res=0,c=0;
        bool flag=false;
        if(mp.size() == 1) return s.size();
        for(auto i : mp){
            if(i.second%2==0) res+=i.second;
            else {
                res+=i.second;
                if(!flag){
                    flag=true;
                }
                else{
                    res--;
                }
            }
            
        }
       return res;
        
        
        
    }
};