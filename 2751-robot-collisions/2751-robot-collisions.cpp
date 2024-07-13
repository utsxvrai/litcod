class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       int n = positions.size();
        vector<pair<int, pair<int, char>>> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {positions[i], {healths[i], directions[i]}};
        }
        sort(a.begin(), a.end());
        stack<pair<int, int>> right;

        for (int i = 0; i < n; ++i) {
            if (a[i].second.second == 'R')
                right.push({a[i].first, a[i].second.first});
            else {
                while (!right.empty() && a[i].second.first > 0) {
                    if (right.top().second == a[i].second.first) {
                        right.pop();
                        a[i].second.first = 0;
                    } else if (right.top().second < a[i].second.first) {
                        right.pop();
                        --a[i].second.first;
                    } else {
                        --right.top().second;
                        a[i].second.first = 0;
                    }
                }
            }
        }

        vector<int> ans;
        unordered_map<int, int> res;

        while (!right.empty()) {
            res[right.top().first] = right.top().second;
            right.pop();
        }

        for (int i = 0; i < n; ++i) {
            if (a[i].second.second == 'L' && a[i].second.first > 0)
                res[a[i].first] = a[i].second.first;
        }

        for (int i = 0; i < n; ++i) {
            if (res.count(positions[i]))
                ans.push_back(res[positions[i]]);
        }
        return ans; 
    }
};