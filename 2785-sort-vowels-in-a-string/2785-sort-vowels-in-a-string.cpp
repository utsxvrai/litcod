class Solution {
public:
    
        bool isVowel(char c) {
        return c=='A' || c=='E' || c=='I' || c=='O' || c=='U' 
        || c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    string sortVowels(string s) {
        string siu="";
        for(int i=0;i<s.length();i++) {
            if(isVowel(s[i])) {
                siu+=s[i];
            }
        }
        sort(siu.begin(),siu.end());
        int index=0;
        for(int i=0;i<s.length();i++) {
            if(isVowel(s[i])) {
                s[i]=siu[index++];
            }
        }
        return s;
    }
};