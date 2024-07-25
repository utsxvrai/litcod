class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freqs;
        int l = nums.size() + 1;

        // Step 1: Count frequencies
        for (int num : nums) {
            freqs[num]++;
        }

        // Step 2: Prepare counting buckets
        vector<vector<bool>> count(l, vector<bool>(201, false));
        for (auto& [num, freq] : freqs) {
            count[freq][100 - num] = true;
        }

        // Step 3: Reconstruct the sorted list
        vector<int> sorted;
        for (int freq = 0; freq < l; ++freq) {
            for (int n = 0; n < 201; ++n) {
                if (count[freq][n]) {
                    for (int i = 0; i < freq; ++i) {
                        sorted.push_back(100 - n);
                    }
                }
            }
        }

        return sorted;
    }
};