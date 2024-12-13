class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); // Tracks whether an element is marked
        long long score = 0;

        // Create a vector of pairs (value, index) to sort and process elements by value
        vector<pair<int, int>> elements;
        for (int i = 0; i < n; ++i) {
            elements.emplace_back(nums[i], i);
        }

        // Sort elements by value, and by index in case of ties
        sort(elements.begin(), elements.end());

        // Process each element in sorted order
        for (const auto& [value, index] : elements) {
            if (!marked[index]) { // If the element is not already marked
                score += value;
                marked[index] = true; // Mark the current element

                // Mark adjacent elements if they exist
                if (index > 0) {
                    marked[index - 1] = true;
                }
                if (index < n - 1) {
                    marked[index + 1] = true;
                }
            }
        }

        return score;
    }
};