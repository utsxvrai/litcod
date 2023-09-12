class Solution {
public:
    int minDeletions(string s) {
         int arr[26] = {0};
        for(int i=0;i<s.size();i++)
            arr[s[i]-'a']++;
        
        vector<int>v;
        for(int i=0;i<26;i++)
            if(arr[i] > 0)
                v.push_back(arr[i]);
        
        sort(v.begin(),v.end());

        int ans = 0;
        for(int i=v.size()-2;i>=0;i--){
            if(v[i+1] == 0){
                ans += v[i];
                v[i] = 0;
            }
            else if(v[i] >= v[i+1]){
                ans += v[i]-v[i+1]+1;
                v[i] = v[i+1]-1;
            }
        }

        return ans;
    }
};