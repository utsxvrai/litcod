class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        sort(hours.begin(),hours.end());
        return hours.size()-(lower_bound(hours.begin(),hours.end(),target)-hours.begin());
    }
};