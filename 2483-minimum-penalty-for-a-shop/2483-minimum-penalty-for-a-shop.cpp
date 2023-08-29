class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), diff = 0, ans = -1, mini = INT_MAX;
        vector<int>prefixN(n,0),suffixY(n,0);
        
        prefixN[0] = (customers[0]=='N');
        for(int i=1;i<n;i++){
            prefixN[i] = (customers[i]=='N') + prefixN[i-1];
        }
        
        suffixY[n-1] = (customers[n-1]=='Y');
        for(int i=n-2;i>=0;i--){
            suffixY[i] = (customers[i]=='Y') + suffixY[i+1];
        }
        
        for(int i=0;i<=n;i++){
            int total = 0;
            if(i==0)total = suffixY[i];
            else if(i==n)total = prefixN[i-1];
            else total = suffixY[i] + prefixN[i-1];
            if(total<mini){
                mini = total;
                ans = i;
            }
        }
        
        return ans;
        
    }
};