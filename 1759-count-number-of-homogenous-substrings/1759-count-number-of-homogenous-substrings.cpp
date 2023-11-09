class Solution {
    long long mod=1e9+7;
public:
    int countHomogenous(string s) {
        int ctr=1;
        vector<int> siu;
        
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                siu.push_back(ctr);ctr=1;
            }
            else{
                ctr++;
            }
        }
        siu.push_back(ctr);
        
        long long messi=0;
        for(int i=0;i<siu.size();i++){
            messi=(messi+(long long)siu[i]*(siu[i]+1)/2)%mod;
        }
        return messi;
    }
};