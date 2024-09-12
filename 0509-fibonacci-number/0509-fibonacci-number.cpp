class Solution {
public:
    int fib(int n) {
        // Base cases for n = 0 and n = 1
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        // Variables to store previous Fibonacci numbers
        int a = 0, b = 1, c;
        
        // Iteratively calculate Fibonacci numbers
        for (int i = 2; i <= n; i++) {
            c = a + b;  // Current Fibonacci number
            a = b;      // Move to next Fibonacci numbers
            b = c;
        }
        return b;
    }
};
