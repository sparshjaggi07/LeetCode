class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long totalSum = 0, leftSum = 0;
        int count = 0;

        for (int num : nums) {
            totalSum += num;
        }

        for (int i = 0; i < nums.size() - 1; ++i) {
            leftSum += nums[i];
            if (leftSum >= totalSum - leftSum) {
                ++count;
            }
        }

        return count;
    }
};
