class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefixSum(words.size() + 1, 0);
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        for (int i = 0; i < words.size(); i++) {
            char firstChar = words[i][0];
            char lastChar = words[i].back();
            if (vowels.count(firstChar) && vowels.count(lastChar)) {
                prefixSum[i + 1] = prefixSum[i] + 1;
            } else {
                prefixSum[i + 1] = prefixSum[i];
            }
        }
        
        vector<int> result;
        for (const auto& query : queries) {
            int left = query[0];
            int right = query[1];
            result.push_back(prefixSum[right + 1] - prefixSum[left]);
        }
        
        return result;
    }
};
