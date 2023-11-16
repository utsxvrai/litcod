class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string siu;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i][i] == '0') { siu += '1'; }
            else { siu += '0'; }

        }

        return siu;
    }
};