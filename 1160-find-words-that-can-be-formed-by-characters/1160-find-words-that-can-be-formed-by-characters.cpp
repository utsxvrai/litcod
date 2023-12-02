class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        map<char,int>mp;
        for(auto it:chars){
            mp[it]++;
        }
        int siu=0;
        for(auto it:words){
            int x=1;
            map<char,int>m;
            for(auto i:it){
                if(++m[i]>mp[i]){
                    x=0;
                    break;
                }
            }
            if(x)siu+=it.size();
        }
        return siu;
    }
};