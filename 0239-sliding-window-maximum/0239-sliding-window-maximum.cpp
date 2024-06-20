class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> res;

        // Handle edge case: window size larger than array size
        if (k > nums.size()) return res;

        int n = nums.size();
        int maxIndex = 0; // Index of the maximum element in the current window

        // Initialize the result with the maximum element for the first window
        for (int i = 0; i < k; ++i) {
            if (nums[i] >= nums[maxIndex]) {
                maxIndex = i;
            }
        }
        res.push_back(nums[maxIndex]);

        // Iterate over the remaining elements, updating the result
        for (int i = k; i < n; ++i) {
            // Check if the current element is greater than the current maximum
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i; // Update the maximum element index
            }

            // Check if the front element is outside the window
            if (i - k + 1 > maxIndex) {
                // Find the new maximum element within the current window (excluding i-k+1)
                maxIndex = i;
                for (int j = i - k + 1; j <= i; ++j) {
                    if (nums[j] >= nums[maxIndex]) {
                        maxIndex = j;
                    }
                }
            }

            // Add the maximum element within the current window to the result
            res.push_back(nums[maxIndex]);
        }

        return res;
        
    }
};