class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<int> left(26, 0), right(26, 0);
        for (char c : s) right[c - 'a']++;
        unordered_set<string> palindromes;
        
        for (int i = 0; i < n; i++) {
            right[s[i] - 'a']--;
            for (int j = 0; j < 26; j++) {
                if (left[j] > 0 && right[j] > 0) {
                    palindromes.insert(string(1, 'a' + j) + s[i] + string(1, 'a' + j));
                }
            }
            left[s[i] - 'a']++;
        }
        
        return palindromes.size();
    }
};
