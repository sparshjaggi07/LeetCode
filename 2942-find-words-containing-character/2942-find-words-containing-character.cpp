class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> arr;
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                if (c == x) {
                    arr.push_back(i); 
                    break;
                }
            }
        }
        return arr;
    }
};