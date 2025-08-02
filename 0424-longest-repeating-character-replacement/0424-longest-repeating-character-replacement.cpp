class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> mp;
        int l = 0, maxf = 0, maxlen = 0;

        for (int r = 0; r < s.size(); r++) {
            mp[s[r] - 'A']++;
            maxf = max(maxf, mp[s[r] - 'A']);
            while ((r - l + 1) - maxf > k) {
                mp[s[l] - 'A']--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
