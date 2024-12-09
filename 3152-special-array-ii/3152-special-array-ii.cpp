class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // Step 1: Compute is_special array
        vector<int> is_special(n - 1, 0);
        for (int i = 0; i < n - 1; ++i) {
            if ((nums[i] % 2) != (nums[i + 1] % 2)) {
                is_special[i] = 1;
            }
        }
        
        // Step 2: Compute prefix_special array
        vector<int> prefix_special(n, 0);
        for (int i = 1; i < n; ++i) {
            prefix_special[i] = prefix_special[i - 1] + (i - 1 < is_special.size() ? is_special[i - 1] : 0);
        }
        
        // Step 3: Answer the queries
        vector<bool> result;
        for (const auto& query : queries) {
            int fromi = query[0], toi = query[1];
            if (toi == fromi) { // Single element subarray is always special
                result.push_back(true);
            } else {
                int special_count = prefix_special[toi] - prefix_special[fromi];
                result.push_back(special_count == (toi - fromi));
            }
        }
        
        return result;
    }
};
