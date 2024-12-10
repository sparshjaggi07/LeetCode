class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxLength = -1;
        
        // Iterate over all starting points of substrings
        for (int i = 0; i < n; ++i) {
            int j = i;
            // Expand while the substring is "special" (all same characters)
            while (j < n && s[j] == s[i]) {
                string substring = s.substr(i, j - i + 1);
                int count = 0;

                // Count occurrences of substring in s
                for (size_t k = 0; k + substring.size() <= s.size(); ++k) {
                    if (s.substr(k, substring.size()) == substring) {
                        ++count;
                    }
                }

                // Update maxLength if this substring occurs at least 3 times
                if (count >= 3) {
                    maxLength = max(maxLength, j - i + 1);
                }
                ++j;
            }
        }
        
        return maxLength;
    }
};
