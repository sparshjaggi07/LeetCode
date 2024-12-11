#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Define the range of possible values
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        
        // Use a frequency array
        int offset = 100000; // To handle negative indices
        vector<int> freq(2 * offset + 1, 0);

        // Update the difference array
        for (int num : nums) {
            freq[num - k + offset]++;
            freq[num + k + 1 + offset]--;
        }

        // Calculate the maximum beauty using a sweep-line approach
        int maxBeauty = 0, currentBeauty = 0;
        for (int count : freq) {
            currentBeauty += count;
            maxBeauty = max(maxBeauty, currentBeauty);
        }

        return maxBeauty;
    }
};
