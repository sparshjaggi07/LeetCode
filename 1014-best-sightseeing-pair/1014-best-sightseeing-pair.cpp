class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0, maxVal = values[0];
        for (int j = 1; j < values.size(); j++) {
            maxScore = max(maxScore, maxVal + values[j] - j);
            maxVal = max(maxVal, values[j] + j);
        }
        return maxScore;
    }
};
