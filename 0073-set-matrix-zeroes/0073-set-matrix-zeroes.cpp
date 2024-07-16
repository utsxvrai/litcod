class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        vector<pair<int,int>> z;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++ ){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    z.push_back({i,j});
                }
            }
        }
        
        int k = z.size();
        for(int i = 0 ; i < k ; i++){
            int row = z[i].first;
            int col = z[i].second;
            
            int g = 0;
            while(g<m){
                mat[row][g++]=0;
            }
            int h = 0;
            while(h<n){
                mat[h++][col]=0;
            }
        }
        
    }
};