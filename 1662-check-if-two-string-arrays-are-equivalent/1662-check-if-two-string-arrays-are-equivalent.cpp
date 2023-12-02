class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0, a = 0, b = 0;
        while (i < word1.size() && j < word2.size()) {
            if (word1[i][a] != word2[j][b])
                return false;
            if (a < word1[i].size() - 1)
                a++;
            else {
                i++;
                a = 0;
            }
            if (b < word2[j].size() - 1)
                b++;
            else {
                j++;
                b = 0;
            }
        }
        return i == word1.size() && j == word2.size();
    }
};