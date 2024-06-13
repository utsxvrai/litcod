class Solution {
public:
    bool isAlphaOrDigit(char c) {
    return std::isalpha(c) || std::isdigit(c);
}
    bool isPalindrome(string s) {
        // if(s.size() == 2 && (s[0]!=s[1])) return false;
        int l(0) , h(s.size() - 1);
        while(l<=h){
            if(!(isAlphaOrDigit(s[l]))){
                l++;
                continue;
            }
            if(!(isAlphaOrDigit(s[h]))){
                h--;
                continue;
            }
            char a = s[l];
            char b = s[h];
            a = tolower(a);
            b = tolower(b);
            // cout<<a<<b<<endl;
            
            if(a!=b){
                return false;
            }
            l++;
            h--;
        }
        return true;
        
    }
};