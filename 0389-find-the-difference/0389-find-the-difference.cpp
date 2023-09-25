class Solution {
public:
    char findTheDifference(string s, string t) {
        char x=' ';
        string siu=s+t;
        for(int i = 0 ; i < siu.size(); i++){
            x^=siu[i];
        }
        return x+32;
        
        
    }
};