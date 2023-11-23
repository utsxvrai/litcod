class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> siu;
        for(int i = 0;i < l.size();i++){
            int arr[r[i] - l[i] + 1];
            int m = 0;
            for(int j = l[i];j <= r[i];j++)
                arr[m++] = nums[j];
            sort(arr,arr + m);
            int diff = arr[1] - arr[0];
            bool flag = true;
            for(int j = 0; j < m-1;j++){
                if(diff != arr[j+1] - arr[j]){
                    siu.push_back(false);
                    flag = false;
                    break;
                }
            }
            if(flag)
                siu.push_back(true);
        }
        return siu;
    }
};