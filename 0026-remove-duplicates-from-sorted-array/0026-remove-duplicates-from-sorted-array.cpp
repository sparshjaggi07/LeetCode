#include <vector>
#include <algorithm> // for unique
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Use the set to store unique elements
        set<int> s(nums.begin(), nums.end());

        // Update nums with unique elements from the set
        nums.assign(s.begin(), s.end());

        // Return the new size of the vector
        return nums.size();
    }
};
