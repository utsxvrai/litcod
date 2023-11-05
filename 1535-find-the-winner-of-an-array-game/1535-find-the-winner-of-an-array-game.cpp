class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int siu = arr[0], mes = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > siu) {
                siu =arr[i];
                mes = 0;
            }
            if (++mes == k) break;
        }
        return siu;
    }
};