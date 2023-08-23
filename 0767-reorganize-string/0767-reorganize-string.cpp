class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int,char>>q;
        int dp[26] = {0};
        for(int i=0;i<s.size();i++){
            dp[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            char t = (char)('a'+i);
            if(dp[i]>0){
                //cout<<dp[i]<<endl;
                q.push({dp[i],t});
            }
        }
        string ans = "";
        while(q.size()>1){
            auto t1 = q.top();
            q.pop();
            auto t2 = q.top();
            q.pop();
            ans += t1.second;
            ans += t2.second;
            if(t1.first>1){
                q.push({t1.first-1,t1.second});
            }
            if(t2.first>1){
                q.push({t2.first-1,t2.second});
            }
        }
        if(q.size()==1){
            auto t = q.top();
            q.pop();
            if(t.first>1){
                return "";
            }
            if(ans.size()==0){
                ans += t.second;
            }
            else if(ans[ans.size()-1]!=t.second){
                ans += t.second;
            }
            else if(ans[0]!=t.second){
                ans = t.second + ans;
            }
            else{
                return "";
            }
        }
        return ans;
    }
};