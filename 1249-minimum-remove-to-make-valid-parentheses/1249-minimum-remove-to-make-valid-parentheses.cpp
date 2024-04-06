class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string t;
        int p=0, n=s.size();
        for(char c: s){
            p+=(c=='(')-(c==')');
            if (p>=0) t.push_back(c);
            else p=0;
        }
        p=0;
        deque<char> q;
        for(int i=t.size()-1; i>=0; i--){
            char c=t[i];
            p+=(c=='(')-(c==')');
            if (p<=0)q.push_front(c);
            else p=0;
        }
        return string(q.begin(), q.end());
        
    }
};