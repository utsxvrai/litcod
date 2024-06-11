class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v(1001,0);
        for(int i = 0 ; i < arr1.size() ; i++){
            v[arr1[i]]++;
        }
        int n = arr1.size();
        vector<int> res;
        for(int  i = 0 ; i < arr2.size() ; i++){
            int m = v[arr2[i]];
            for(int j = 0 ; j < m ; j++){
                res.push_back(arr2[i]);
                v[arr2[i]] = 0;
            }
            
        }
        for(int i = 0 ; i < 1001 ; i++){
            if(v[i]!=0){
                int m = v[i];
                res.insert(res.end(), m, i);
            }
        }
        
        
        return res;
        
    }
};