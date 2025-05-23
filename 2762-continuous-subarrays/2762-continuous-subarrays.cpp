class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        int left = 0; 
        multiset<int> window;
        
        for (int right = 0; right < n; ++right) {
            window.insert(nums[right]);
            while (*window.rbegin() - *window.begin() > 2) {
                window.erase(window.find(nums[left]));
                ++left;
            }
            count += (right - left + 1);
        }
        
        return count;
    }
};
