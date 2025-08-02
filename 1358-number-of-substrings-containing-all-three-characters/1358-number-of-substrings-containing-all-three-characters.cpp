class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        unordered_map<char, int> mp;
        mp['a'] = mp['b'] = mp['c'] = -1;

        for(int i = 0; i < s.length(); i++) {
            mp[s[i]] = i;

            if(mp['a'] != -1 && mp['b'] != -1 && mp['c'] != -1) {
                cnt += min({mp['a'], mp['b'], mp['c']}) + 1;
            }
        }

        return cnt;
    }
};
