class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int n = matrix.size(), m = matrix[0].size(), res = 0;

        for(int i = 1; i < n; i ++)
        {
            // Summing all 1's columnwise
            for(int j = 0; j < m; j++) 
            {
                matrix[i][j] += matrix[i][j] ? matrix[i - 1][j] : 0;
                // cout << matrix[i][j] << " ";
            }
            // cout << endl;
        }

        for(int i = 0; i < n; i ++)
        {
            // sorting rows on the bases of 1's 
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for(int j = 0; j < m; j++) 
                res = max(res, matrix[i][j] * (j + 1)); // get max submatrix 
        }
        return res;
    }
};