class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1; 
        int prev2 = 1, prev = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev2 + prev;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};