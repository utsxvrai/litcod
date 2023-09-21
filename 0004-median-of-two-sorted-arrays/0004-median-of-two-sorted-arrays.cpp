class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;

        while (low <= high) {
            int p1 = (low + high) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int maxLeft1 = (p1 == 0) ? INT_MIN : nums1[p1 - 1];
            int minRight1 = (p1 == m) ? INT_MAX : nums1[p1];

            int maxLeft2 = (p2 == 0) ? INT_MIN : nums2[p2 - 1];
            int minRight2 = (p2 == n) ? INT_MAX : nums2[p2];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((m + n) % 2 == 0) {
                    return (double)(max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return (double)max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = p1 - 1;
            } else {
                low = p1 + 1;
            }
        }
        
        // Return a value (e.g., -1) if the correct partition is not found
        return -1;
    }
};
