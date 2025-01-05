class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shiftEffect(s.size() + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0], end = shift[1], direction = shift[2];
            int value = (direction == 1) ? 1 : -1;
            shiftEffect[start] += value;
            shiftEffect[end + 1] -= value;
        }
        int cumulativeShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            cumulativeShift += shiftEffect[i];
            int newChar = (s[i] - 'a' + cumulativeShift) % 26;
            if (newChar < 0) newChar += 26;
            s[i] = 'a' + newChar;
        }
        return s;
    }
};
