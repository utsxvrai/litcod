class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int i,j,k,n = dist.size();
        unordered_map<int, int> siu;
        for(i = 0; i < n; ++i){
            int time = ceil((float)dist[i] / (float)speed[i]);
            siu[time]++; 
        }
        int ans = 0, it = 1;
        for(i = 1; i <= n; ++i){
            ans++;
            it -= siu[i];
            if(it < 0){
                break;
            }
            it++;
        }
        return ans;
    }
};