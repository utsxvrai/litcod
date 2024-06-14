class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        unordered_map<char, int> charIndexMap;
        int maxLength = 0, left = 0;

        for (int right = 0; right < n; right++) {
            char currentChar = s[right];

            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                left = charIndexMap[currentChar] + 1;
            }

            charIndexMap[currentChar] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
        
        
        
    }
};