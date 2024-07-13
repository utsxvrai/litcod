class Solution {
private:
    int search(vector<vector<int>>& matrix, int target,int i , int j) {
        int low = 0;
        int high = j - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] < target) {
                low = mid + 1;
            } else if (matrix[i][mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int i = 0 ; i < n ; i++){
            if(target >= matrix[i][0] && target <= matrix[i][m-1]){
                if(search(matrix, target, i, m) != -1) return true;
            }
        }
        return false;
    }
};