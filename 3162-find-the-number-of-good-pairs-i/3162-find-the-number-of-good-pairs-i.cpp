class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;

        for (int x : nums1) {
            if (x % k == 0) {
                int f = x / k;
                map1[f]++;
            }
        }

        for (int x : nums2) {
            map2[x]++;
        }

        int res = 0;
        for (const auto& [x, y] : map1) {
            for (int i = 1; i <= sqrt(x); ++i) {
                if (x % i == 0) {
                    int cur = x / i;
                    if (map2.find(i) != map2.end()) {
                        res += map2[i] * y;
                    }
                    if (cur != i && map2.find(cur) != map2.end()) {
                        res += map2[cur] * y;
                    }
                }
            }
        }

        return res;
        
    }
};