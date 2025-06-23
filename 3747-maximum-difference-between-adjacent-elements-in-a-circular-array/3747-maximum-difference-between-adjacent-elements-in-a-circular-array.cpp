class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxi=-1e9;
        for(int i=0;i<nums.size()-1;i++){
            int diff=abs(nums[i]-nums[i+1]);
            maxi=max(maxi,diff);
        }
        if(abs(nums[nums.size()-1]-nums[0])>maxi) return maxi= abs(nums[nums.size()-1]-nums[0]);
        return maxi;
    }
};