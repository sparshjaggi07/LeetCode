class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> result(n, 0);
        int count = 0, steps = 0;

        for (int i = 0; i < n; ++i) {
            result[i] += steps;
            count += boxes[i] == '1' ? 1 : 0;
            steps += count;
        }

        count = steps = 0;
        for (int i = n - 1; i >= 0; --i) {
            result[i] += steps;
            count += boxes[i] == '1' ? 1 : 0;
            steps += count;
        }

        return result;
    }
};
