class Solution {
public:
    const int MOD = 1e9 + 7;

    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pow2(n, 1); 

        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        sort(nums.begin(), nums.end());

        int i = 0, j = n - 1, result = 0;

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                result = (result + pow2[j - i]) % MOD;
                ++i;
            } else {
                --j;
            }
        }

        return result;
    }
};