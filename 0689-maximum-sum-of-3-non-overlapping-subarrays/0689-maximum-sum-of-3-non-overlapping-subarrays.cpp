class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + nums[i];
        }
        
        vector<int> left(n, 0), right(n, n - k);
        for (int i = k, maxIdx = 0; i < n; ++i) {
            if (sum[i + 1] - sum[i + 1 - k] > sum[maxIdx + k] - sum[maxIdx]) {
                maxIdx = i + 1 - k;
            }
            left[i] = maxIdx;
        }
        
        for (int i = n - k - 1, maxIdx = n - k; i >= 0; --i) {
            if (sum[i + k] - sum[i] >= sum[maxIdx + k] - sum[maxIdx]) {
                maxIdx = i;
            }
            right[i] = maxIdx;
        }
        
        vector<int> result(3, 0);
        int maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1], r = right[i + k];
            int total = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);
            if (total > maxSum) {
                maxSum = total;
                result = {l, i, r};
            }
        }
        return result;
    }
};
