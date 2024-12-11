#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // Difference array using a map
        map<int, int> diff;

        // Update the ranges
        for (int num : nums) {
            diff[num - k]++;
            diff[num + k + 1]--;
        }

        // Calculate the maximum beauty using a sweep-line approach
        int maxBeauty = 0, currentBeauty = 0;
        for (auto& [key, value] : diff) {
            currentBeauty += value;
            maxBeauty = max(maxBeauty, currentBeauty);
        }

        return maxBeauty;
    }
};
