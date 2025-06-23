class Solution {
public:
    long long int helper(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int take = nums[i] + prev2;
            int nottake = prev;
            int curr = max(take, nottake);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    long long int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> temp1(nums.begin() + 1, nums.end());     
        vector<int> temp2(nums.begin(), nums.end() - 1);     

        long long int ans1 = helper(temp1);
        long long int ans2 = helper(temp2);

        return max(ans1, ans2);
    }
};