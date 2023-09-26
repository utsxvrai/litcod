class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> lastOccurrence;
        unordered_set<char> seen;
        string result = "";

        // Store the last occurrence index of each character in the string.
        for (int i = 0; i < s.length(); ++i) {
            lastOccurrence[s[i]] = i;
        }

        for (int i = 0; i < s.length(); ++i) {
            char currentChar = s[i];

            // Skip characters that have already been included in the result.
            if (seen.find(currentChar) != seen.end()) {
                continue;
            }

            // Remove characters from the result that are greater than the current character
            // and have a last occurrence index after the current index.
            while (!result.empty() && currentChar < result.back() && i < lastOccurrence[result.back()]) {
                seen.erase(result.back());
                result.pop_back();
            }

            seen.insert(currentChar);
            result += currentChar;
        }

        return result;
    }
};