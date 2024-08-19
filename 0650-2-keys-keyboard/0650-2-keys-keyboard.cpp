class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        
        int s = 0;
        int f = 2;
        
        while (n > 1) {
            while (n % f == 0) {
                s += f;
                n /= f;
            }
            f++;
        }
        
        return s;
        
    }
};