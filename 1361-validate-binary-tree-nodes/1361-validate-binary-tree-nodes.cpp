class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& RC) {
        int cnt = n-1;
        vector<int> par(n, -1);
        vector<int> vis(n, 0);

        for(int i=0;i<n;i++){
            if(leftChild[i] == -1)continue;
            if(vis[leftChild[i]] == 1) return false;
            // checked for ancestor
            int temp = par[i];
            while(temp != -1){
                if(temp == leftChild[i])return false;
                temp = par[temp];
            }

            par[leftChild[i]] = i;
            vis[leftChild[i]] = 1;
            cnt--;
        }
        for(int i=0;i<n;i++){
            if(RC[i] == -1)continue;
            if(vis[RC[i]] == 1) return false;
            //Checked for ancestor
            int temp = par[i];
            while(temp != -1){
                if(temp == RC[i])return false;
                temp = par[temp];
            }

            par[RC[i]] = i;
            vis[RC[i]] = 1;
            cnt--;
        }
        if(cnt != 0)return false;
        return true;  
    }
};