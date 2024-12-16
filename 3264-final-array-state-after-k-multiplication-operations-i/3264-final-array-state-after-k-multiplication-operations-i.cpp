class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k > 0) {
            // Find the minimum value and its index
            int minIndex = 0;
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] < nums[minIndex]) {
                    minIndex = i;
                }
            }
            // Replace the minimum value with its multiplied value
            nums[minIndex] *= multiplier;
            --k;
        }
        return nums;
    }
};