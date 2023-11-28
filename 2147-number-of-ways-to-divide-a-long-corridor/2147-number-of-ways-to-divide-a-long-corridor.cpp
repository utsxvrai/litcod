class Solution {
public:
    int numberOfWays(string corridor) {
        int mod = 1e9+7;
        vector<int>seats;
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S') seats.push_back(i);
        }
        if(seats.size()==2) return 1;
        if(seats.size()%2!=0 || seats.size()==0) return 0;
        else {
            long long ans = 1;
            for(int i=2;i<seats.size();i+=2){
                ans =(ans*(seats[i]-seats[i-1])) % mod;
                // cout<<seats[i]<<" "<<ans<<endl;
            }
            return ans;
    }
    }
};