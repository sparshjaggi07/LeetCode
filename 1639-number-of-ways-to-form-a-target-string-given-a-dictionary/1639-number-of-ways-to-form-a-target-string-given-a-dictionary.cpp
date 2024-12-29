class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int m = words[0].size(), n = target.size();
        int mod = 1e9 + 7;
        vector<vector<int>> charCount(m, vector<int>(26, 0));
        
        for (const auto& word : words) {
            for (int i = 0; i < m; ++i) {
                charCount[i][word[i] - 'a']++;
            }
        }
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i <= n; ++i) {
                dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
                if (i < n && charCount[j][target[i] - 'a'] > 0) {
                    dp[i + 1][j + 1] = (dp[i + 1][j + 1] + (long long)dp[i][j] * charCount[j][target[i] - 'a']) % mod;
                }
            }
        }
        
        return dp[n][m];
    }
};
