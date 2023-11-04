class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int siu = -1e9;
        for (auto& e : left) {
            siu = max(siu, e);
        }
        for (auto& e : right) {
            siu = max(siu, abs(e - n));
        }
        return siu;
    }
};