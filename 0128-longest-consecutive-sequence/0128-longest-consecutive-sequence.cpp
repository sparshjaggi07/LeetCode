class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=1)return nums.size();
        int cnt=1,maxc=INT_MIN;
        for(int i=1;i<nums.size();i++){
            if((nums[i-1]!=nums[i] )&& (nums[i-1]==nums[i]-1)){cnt++;maxc=max(maxc,cnt);}
            else if (nums[i-1]==nums[i]){maxc=max(maxc,cnt);}
            else{ cnt=1;}
        }
        return maxc;
    }
};